from collections import deque

n, k = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[0 for _ in range(n)] for _ in range(n)]

q = deque()
ans = 0

def inRange(x, y):
    return 0<=x<n and 0<=y<n

def canGo(x, y):
    if not inRange(x, y):
        return False
    if grid[x][y] == 1 or visited[x][y]:
        return False
    
    return True



def bfs():
    global ans

    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()
        ans += 1

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if canGo(nx, ny):
                visited[nx][ny] = 1
                q.append((nx, ny))
    

for _ in range(k):
    r, c = tuple(map(int, input().split()))

    visited[r-1][c-1] = 1
    q.append((r-1, c-1))

bfs()

print(ans)