n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [
    [False] * n for _ in range(n)
]

p_num = 0
village = []

def can_go(x, y):
    return 0<=x<n and 0<=y<n and not visited[x][y] and grid[x][y]

def dfs(x, y):
    global p_num

    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny):
            visited[nx][ny] = True
            p_num += 1

            dfs(nx, ny)

for i in range(n):
    for j in range(n):
        if can_go(i, j):
            visited[i][j] = True
            p_num = 1

            dfs(i, j)

            village.append(p_num)

village.sort()

print(len(village))

for p in village:
    print(p)