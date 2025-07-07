MOD = 10007

n = int(input())

nums = [1, 2, 5]

dp = [0] * (n+1)

dp[0] = 1

for i in range(1, n+1):
    for j in nums:
        if i >= j:
            dp[i] = (dp[i] + dp[i-j])%MOD

print(dp[n])

