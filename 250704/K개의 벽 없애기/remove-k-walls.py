import sys
from collections import deque

INT_MAX = sys.maxsize

n, k = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

wall_pos = []
selc_pos = []

r1, c1 = tuple(map(int, input().split()))
r2, c2 = tuple(map(int, input().split()))

r1, c1, r2, c2 = r1-1, c1-1, r2-1, c2-1

q = deque()
visited = [[-1]*n for _ in range(n)]
ans = INT_MAX

def can_go(x, y):
    return 0<=x<n and 0<=y<n and visited[x][y] == -1 and not grid[x][y]


def bfs():
    global visited

    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    visited = [[-1]*n for _ in range(n)]
    q.append((r1, c1))
    visited[r1][c1] = 0

    for x, y in selc_pos:
        grid[x][y] = 0

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
            
            if can_go(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = visited[x][y] + 1

    
    for x, y in selc_pos:
        grid[x][y] = 1


def find_min_dist(idx, cnt):
    global ans

    if cnt == k:
        bfs()
        if visited[r2][c2] != -1:
            ans = min(ans, visited[r2][c2])
        return
    
    if idx >= len(wall_pos):
        return
    
    selc_pos.append(wall_pos[idx])
    find_min_dist(idx+1, cnt+1)
    selc_pos.pop()

    find_min_dist(idx+1, cnt)

for i in range(n):
    for j in range(n):
        if grid[i][j]:
            wall_pos.append((i, j))


find_min_dist(0, 0)

print(ans if ans != INT_MAX else -1)

