from collections import deque
import sys

INT_MAX = sys.maxsize

n, k = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

walls = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if grid[i][j]
]
selc_walls = []

q = deque()
visited = [[INT_MAX for _ in range(n)] for _ in range(n)]

r1, c1 = tuple(map(int, input().split()))
r2, c2 = tuple(map(int, input().split()))

ans = INT_MAX

def can_go(x, y):
    return 0<=x<n and 0<=y<n and visited[x][y] == INT_MAX and not grid[x][y]

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = visited[x][y]+1

def calc():
    for i in range(n):
        for j in range(n):
            visited[i][j] = INT_MAX
    
    for x, y in selc_walls:
        grid[x][y] = 0
    
    q.append((r1-1, c1-1))
    visited[r1-1][c1-1] = 0

    bfs()

    for x, y in selc_walls:
        grid[x][y] = 1
    
    return visited[r2-1][c2-1]


def find_wall(idx, cnt):
    global ans

    if idx == len(walls):
        if cnt == k:
            ans = min(ans, calc())
        return
    
    selc_walls.append(walls[idx])
    find_wall(idx+1, cnt+1)
    selc_walls.pop()

    find_wall(idx+1, cnt)
    


find_wall(0, 0)

print(ans if ans is not INT_MAX else -1)