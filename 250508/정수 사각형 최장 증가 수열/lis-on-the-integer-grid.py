n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dp = [[1]*n for _ in range(n)]

cells = []
ans = 0

for i in range(n):
    for j in range(n):
        cells.append((grid[i][j], i, j))

cells.sort()

dxs, dys = [-1, 1, 0, 0], [0, 0, -1, 1]

for _, x, y in cells:
    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if 0<=nx<n and 0<=ny<n and grid[nx][ny] > grid[x][y]:
            dp[nx][ny] = max(dp[nx][ny], dp[x][y]+1)

ans = max(map(max, dp))

print(ans)