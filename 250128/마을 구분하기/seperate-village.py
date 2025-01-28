n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[0 for _ in range(n)] for _ in range(n)]
village = []

dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]
cnt = 0

def inRange(x, y):
    return 0<=x<n and 0<=y<n

def canGo(x, y):
    if not inRange(x, y):
        return False
    if visited[x][y] or grid[x][y] == 0:
        return False
    
    return True

def dfs(x, y):
    global cnt

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if canGo(nx, ny):
            visited[nx][ny] = 1
            cnt += 1
            dfs(nx, ny)


for i in range(n):
    for j in range(n):
        if grid[i][j] and not visited[i][j]:
            visited[i][j] = 1
            cnt = 1
            dfs(i, j)
            village.append(cnt)

village.sort()
print(len(village))
for num in village:
    print(num)