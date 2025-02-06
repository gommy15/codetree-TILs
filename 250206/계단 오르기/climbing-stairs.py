MOD = 10007

n = int(input())

dp = [0] * 1001

dp[0] = 1
dp[1] = 0
dp[2] = 1

for i in range(3, n+1):
    dp[i] = (dp[i-2] + dp[i-3]) % MOD

print(dp[n])