import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))

coin = list(map(int, input().split()))

dp = [INT_MAX] * (m+1)

dp[0] = 0

for i in range(1, m+1):
    for j in range(n):
        if i >= coin[j]:
            dp[i] = min(dp[i], dp[i-coin[j]]+1)

print(dp[m] if dp[m] is not INT_MAX else -1)