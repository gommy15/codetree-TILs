n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[False]*n for _ in range(n)]
villages = []
people = 1

def can_go(x, y):
    return 0<=x<n and 0<=y<n and not visited[x][y] and grid[x][y]

def dfs(x, y):
    global people

    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny):
            visited[nx][ny] = True
            people += 1
            dfs(nx, ny)

for i in range(n):
    for j in range(n):
        if not visited[i][j] and grid[i][j]:
            people = 1
            visited[i][j] = True

            dfs(i, j)

            villages.append(people)

villages.sort()
print(len(villages))
for p in villages:
    print(p)