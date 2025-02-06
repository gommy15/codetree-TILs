import sys

n = int(input())

a = list(map(int, input().split()))

INT_MIN = -sys.maxsize
dp = [INT_MIN] * n

dp[0] = 0

for i in range(n):
    for j in range(i):
        if a[j]+j >= i and dp[j] != INT_MIN:
            dp[i] = max(dp[i], dp[j]+1)

print(max(dp))