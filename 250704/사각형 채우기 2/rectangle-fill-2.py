n = int(input())

MOD = 10007

dp = [0] * (n+1)

dp[0] = dp[1] = 1
dp[2] = 3

for i in range(3, n+1):
    dp[i] = (dp[i-1] + dp[i-2]*2)%MOD

print(dp[n])