from collections import deque

n, k = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

q = deque()
visited = [[-1 for _ in range(n)] for _ in range(n)]

def can_go(x, y):
    return 0<=x<n and 0<=y<n and visited[x][y] == -1 and grid[x][y] == 1

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = visited[x][y]+1
        

for i in range(n):
    for j in range(n):
        if grid[i][j] == 2:
            q.append((i, j))
            visited[i][j] = 0

bfs()

for i in range(n):
    for j in range(n):
        if grid[i][j] == 1 and visited[i][j] == -1:
            print(-2, end=" ")
        else:
            print(visited[i][j], end = " ")
    
    print()



