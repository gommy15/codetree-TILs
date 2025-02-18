import sys

INT_MIN = -sys.maxsize

n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dp = [[INT_MIN]*m for _ in range(n)]

dp[0][0] = 1

for x in range(1, n):
    for y in range(1, m):
        for i in range(x):
            for j in range(y):
                if grid[i][j] is not INT_MIN and grid[i][j] < grid[x][y]:
                    dp[x][y] = max(dp[x][y], dp[i][j]+1)


ans = INT_MIN
for i in range(n):
    for j in range(m):
        ans = max(ans, dp[i][j])

print(ans)
