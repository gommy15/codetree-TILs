import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))

seq = list(map(int, input().split()))

dp = [INT_MAX]*(m+1)

dp[0] = 0

for i in range(n):
    for j in range(m, -1, -1):
        if j >= seq[i]:
            dp[j] = min(dp[j], dp[j-seq[i]]+1)

print(dp[m] if dp[m] != INT_MAX else -1)