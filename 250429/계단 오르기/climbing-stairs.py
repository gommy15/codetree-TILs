n = int(input())

dp = [0] * (n+1)

dp[2] = 1

for i in range(3, n+1):
    dp[i] = max(dp[i-2], dp[i-3]) + 1

print(dp[n])