from collections import deque

n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

q = deque()
visited = [[0 for _ in range(m)]for _ in range(n)]

def can_go(x, y):
    return 0<=x<n and 0<=y<m and not visited[x][y] and grid[x][y]

def bfs():
    dxs, dys = [-1, 1, 0, 0], [0, 0, -1, 1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                visited[nx][ny] = visited[x][y]+1
                q.append((nx, ny))


q.append((0, 0))
visited[0][0] = 0

bfs()

print(visited[n-1][m-1] if visited[n-1][m-1] is not 0 else -1)