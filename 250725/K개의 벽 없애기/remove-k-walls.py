from collections import deque
import sys

INT_MAX = sys.maxsize

n, k = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

r1, c1 = tuple(map(int, input().split()))
r2, c2 = tuple(map(int, input().split()))

r1-=1
c1-=1
r2-=1
c2-=1

wall = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if grid[i][j] == 1
]

selc_wall = []

visited = [[-1]*n for _ in range(n)]
q = deque()

ans = INT_MAX

def can_go(x, y):
    return 0<=x<n and 0<=y<n and visited[x][y] == -1 and grid[x][y] == 0

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                visited[nx][ny] = visited[x][y]+1
                q.append((nx, ny))

def find_min_time(idx):
    global visited, ans

    if idx == len(wall):
        if len(selc_wall) == k:
            visited = [[-1]*n for _ in range(n)]

            for a, b in selc_wall:
                grid[a][b] = 0

            q.append((r1, c1))
            visited[r1][c1] = 0

            bfs()

            for a, b in selc_wall:
                grid[a][b] = 1

            if visited[r2][c2] != -1:
                ans = min(ans, visited[r2][c2])
        
        return
    
    selc_wall.append(wall[idx])
    find_min_time(idx+1)
    selc_wall.pop()

    find_min_time(idx+1)

find_min_time(0)

print(ans if ans != INT_MAX else -1)