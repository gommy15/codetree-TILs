from collections import deque

n, h, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]
ans = [[0 for _ in range(n)] for _ in range(n)]
q = deque()

def canGo(x, y, visited):
    return 0<=x<n and 0<=y<n and grid[x][y] != 1 and not visited[x][y]

def bfs(i, j):
    visited = [[0 for _ in range(n)] for _ in range(n)]
    step = [[0 for _ in range(n)] for _ in range(n)]
    q.append((i, j))
    visited[i][j] = True
    #step[i][j] = 0

    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            
            if canGo(nx, ny, visited):
                if grid[nx][ny] == 3:
                    ans[i][j] = step[x][y]+1
                    return
                
                q.append((nx, ny))
                visited[nx][ny] = True
                step[nx][ny] = step[x][y]+1

    ans[i][j] = -1



for i in range(n):
    for j in range(n):
        if grid[i][j] == 2:
            bfs(i, j)

for i in range(n):
    for j in range(n):
        print(ans[i][j], end=" ")
    print()