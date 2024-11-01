from collections import deque
import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

q = deque()
visited = [[0 for _ in range(m)] for _ in range(n)]
step = [[0 for _ in range(m)] for _ in range(n)]

ans = INT_MAX

def canGo(x, y):
    return 0<=x<n and 0<=y<n and grid[x][y] and not visited[x][y]

def bfs():
    global ans

    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if canGo(nx, ny):
                visited[nx][ny] = 1
                q.append((nx, ny))
                step[nx][ny] = step[x][y]+1
    
    if visited[n-1][m-1]:
        ans = step[n-1][m-1]
        

visited[0][0] = 1
q.append((0, 0))

bfs()

if ans == INT_MAX:
    ans = -1

print(ans)