import sys

n = int(input())

dp= [0] * (n+1)

if n==1:
    print(1)
    sys.exit()

dp[1] = dp[2] = 1

for i in range(3, n+1):
    dp[i] = dp[i-1] + dp[i-2]

print(dp[n])