import sys
from collections import deque

INT_MAX = sys.maxsize

n, k = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

r1, c1 = tuple(map(int, input().split()))
r2, c2 = tuple(map(int, input().split()))

r1, c1, r2, c2 = r1-1, c1-1, r2-1, c2-1

stone_pos = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if grid[i][j]
]

q = deque()
visited = [[-1]*n for _ in range(n)]

ans = INT_MAX

def can_go(x, y):
    return 0<=x<n and 0<=y<n and visited[x][y] == -1 and not grid[x][y]

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = visited[x][y]+1

    return visited[r2][c2] if visited[r2][c2] != -1 else INT_MAX

def find_min(idx, cnt):
    global ans, visited

    if idx == len(stone_pos):
        if cnt == k:
            visited = [[-1]*n for _ in range(n)]

            q.append((r1, c1))
            visited[r1][c1] = 0

            ans = min(ans, bfs())

        return

    x, y = stone_pos[idx]
    grid[x][y] = 0
    find_min(idx+1, cnt+1)
    grid[x][y] = 1

    find_min(idx+1, cnt)

find_min(0, 0)

if ans == INT_MAX:
    ans = -1

print(ans)