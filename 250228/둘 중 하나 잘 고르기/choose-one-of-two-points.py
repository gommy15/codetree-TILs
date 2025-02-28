n = int(input())

card = [(0, 0)] + [
    tuple(map(int, input().split()))
    for _ in range(2*n)
]

dp = [[0]*(n+1) for _ in range(n+1)]

for i in range(1, n+1):
    r, b = card[i]
    dp[i][0] = dp[i-1][0] + r
    dp[0][i] = dp[0][i-1] + b

for i in range(1, n+1):
    for j in range(1, n+1):
        r, b = card[i+j]
        dp[i][j] = max(dp[i][j], dp[i-1][j] + r)
        dp[i][j] = max(dp[i][j], dp[i][j-1] + b)

print(dp[n][n])