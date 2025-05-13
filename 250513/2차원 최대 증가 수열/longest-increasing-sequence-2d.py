n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dp = [[-1]*m for _ in range(n)]

dp[0][0] = 1

for i in range(1, n):
    for j in range(1, m):
        for x in range(0, i):
            for y in range(0, j):
                if dp[x][y] == -1:
                    continue

                if grid[x][y] < grid[i][j]:
                    dp[i][j] = max(dp[i][j], dp[x][y]+1)

print(max(map(max, dp)))