n, m = tuple(map(int, input().split()))

coins = list(map(int, input().split()))

dp = [-1] * (m+1)

dp[0] = 0

for i in range(1, m+1):
    for coin in coins:
        if i >= coin and dp[i-coin] != -1:
            dp[i] = max(dp[i], dp[i-coin]+1)

print(dp[m])