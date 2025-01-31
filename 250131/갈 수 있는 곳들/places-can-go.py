from collections import deque

n, k = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[0 for _ in range(n)] for _ in range(n)]

q = deque()

def cango(x, y):
    return 0<=x<n and 0<=y<n and not grid[x][y] and not visited[x][y]

def bfs():
    dxs, dys = [-1, 1, 0, 0], [0, 0, -1, 1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if cango(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = 1


for _ in range(k):
    r, c = tuple(map(int, input().split()))

    q.append((r-1, c-1))
    visited[r-1][c-1] = 1

bfs()

print(sum([
    visited[i][j]
    for i in range(n)
    for j in range(n)
]))

