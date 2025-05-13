import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))

coins = list(map(int, input().split()))

dp = [INT_MAX]*(m+1)

dp[0] = 0

for i in range(1, m+1):
    for j in range(n):
        if i-coins[j] >= 0:
            dp[i] = min(dp[i], dp[i-coins[j]]+1)

print(dp[m] if dp[m] != INT_MAX else -1)
