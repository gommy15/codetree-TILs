n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dp = [[1]*n for _ in range(n)]
cells = []

for i in range(n):
    for j in range(n):
        cells.append((grid[i][j], i, j))

cells.sort()

def can_go(x, y, num):
    return 0<=x<n and 0<=y<n and grid[x][y] > num

dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

for _, x, y in cells:

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny, grid[x][y]):
            dp[nx][ny] = max(dp[nx][ny], dp[x][y]+1)

print(max(map(max, dp)))
