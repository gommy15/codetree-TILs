import sys

INT_MIN = -sys.maxsize

n = int(input())
arr = [0]+list(map(int, input().split()))

dp = [INT_MIN] * (n+1)

for i in range(1, n+1):
    dp[i] = max(dp[i-1]+arr[i], arr[i])

print(max(dp))
