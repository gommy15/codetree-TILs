import sys
INT_MAX = sys.maxsize

n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dp = [[(INT_MAX, 0, 0)]*n for _ in range(n)]

dp[0][0] = (INT_MAX, grid[0][0], grid[0][0])

for i in range(1, n):
    mx = max(dp[i-1][0][2], grid[i][0])
    mn = min(dp[i-1][0][1], grid[i][0])

    dp[i][0] = (abs(mx-mn), mn, mx)

    mx = max(dp[0][i-1][2], grid[0][i])
    mn = min(dp[0][i-1][1], grid[0][i])

    dp[0][i] = (abs(mx-mn), mn, mx)

for i in range(1, n):
    for j in range(1, n):
        mx1 = max(dp[i-1][j][2], grid[i][j])
        mn1 = min(dp[i-1][j][1], grid[i][j])

        mx2 = max(dp[i][j-1][2], grid[i][j])
        mn2 = min(dp[i][j-1][1], grid[i][j])

        if abs(mx1-mn1) < abs(mx2-mn2):
            dp[i][j] = (abs(mx1-mn1), mn1, mx1)
        else:
            dp[i][j] = (abs(mx2-mn2), mn2, mx2)

print(dp[n-1][n-1][0])