n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dp = [[0]*n for _ in range(n)]

dp[0][0] = 1

for i in range(1, n):
    for j in range(1, n):
        for k in range(i):
            for l in range(j):
                if grid[k][l] < grid[i][j]:
                    dp[i][j] = max(dp[i][j], dp[k][l]+1)

print(max(map(max, dp)))