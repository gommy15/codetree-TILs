MOD = 10007
MAX_M = 3

n = int(input())

dp = [0] * (n+1)
numbers = [1, 2, 5]

dp[0] = 1

for i in range(n+1):
    for j in range(MAX_M):
        if i >= numbers[j]:
            dp[i] = (dp[i] + dp[i-numbers[j]])%MOD


print(dp[n])