n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

visited = [[False]*n for _ in range(n)]
village = []

cnt = 0

def can_go(x, y):
    return 0<=x<n and 0<=y<n and grid[x][y] and not visited[x][y]

def dfs(x, y):
    global cnt

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny):
            visited[nx][ny] = True
            cnt += 1
            dfs(nx, ny)

for i in range(n):
    for j in range(n):
        if not visited[i][j] and grid[i][j]:
            visited[i][j] = True
            cnt = 1
            dfs(i, j)

            village.append(cnt)

village.sort()

print(len(village))
for v in village:
    print(v)