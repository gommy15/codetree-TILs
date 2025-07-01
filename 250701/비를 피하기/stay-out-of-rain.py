from collections import deque

n, h, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

s_pos = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if grid[i][j] == 3
]

q = deque()
visited = [[-1]*n for _ in range(n)]

def can_go(x, y):
    return 0<=x<n and 0<=y<n and visited[x][y] == -1 and grid[x][y] != 1

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = visited[x][y] + 1


for x, y in s_pos:
    q.append((x, y))
    visited[x][y] = 0

bfs()

for i in range(n):
    for j in range(n):
        if grid[i][j] != 2:
            print(0, end = " ")
        else:
            print(visited[i][j], end = " ")
    print()