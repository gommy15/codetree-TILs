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

def in_range(x, y):
    return 0<=x<n and 0<=y<n

for _, x, y in cells:
    
    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if in_range(nx, ny) and grid[x][y] < grid[nx][ny]:
            dp[nx][ny] = max(dp[nx][ny], dp[x][y]+1)

for i in range(n):
    for j in range(n):
        ans = max(ans, dp[i][j])

print(ans)