n, m = tuple(map(int, input().split()))

info = [[0, 0]] + [
    tuple(map(int, input().split()))
    for _ in range(n)
]

dp = [[0]*(m+1) for _ in range(n+1)]

dp[0][0] = 0

for i in range(1, n+1):
    for j in range(m+1):
        if j >= info[i][0]:
            dp[i][j] = max(dp[i-1][j-info[i][0]]+info[i][1], dp[i-1][j])
        else:
            dp[i][j] = dp[i-1][j]

print(dp[n][m])
