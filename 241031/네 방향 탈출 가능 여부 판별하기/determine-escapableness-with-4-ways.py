from collections import deque

n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[0 for _ in range(m)] for _ in range(n)]

q = deque()

def inRange(x, y):
    return 0<=x<n and 0<=y<m

def canGo(x, y):
    if not inRange(x, y):
        return False
    if grid[x][y] == 0 or visited[x][y]:
        return False
    
    return True

def bfs():
    while q:
        x, y = q.popleft()

        dxs, dys = [-1, 0, 1, 1], [0, 1, 0, -1]
        
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if canGo(nx, ny):
                visited[nx][ny] = 1
                q.append((nx, ny))


visited[0][0] = 1
q.append((0, 0))
bfs()

print(visited[n-1][m-1])