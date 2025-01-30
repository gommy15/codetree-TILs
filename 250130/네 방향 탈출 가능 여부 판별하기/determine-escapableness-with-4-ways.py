from collections import deque

n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[0 for _ in range(m)] for _ in range(n)]

dxs, dys = [-1, 1, 0, 0], [0, 0, -1, 1]

q = deque()

def inRange(x, y):
    return 0<=x<n and 0<=y<m

def can_go(x, y):
    return inRange(x, y) and grid[x][y] and not visited[x][y]

def bfs():
    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = 1

q.append((0, 0))
visited[0][0] = 1

bfs()

print(visited[n-1][m-1])