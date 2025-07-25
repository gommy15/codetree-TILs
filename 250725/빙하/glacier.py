from collections import deque

n, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[False]*m for _ in range(n)]
water = deque()
glac = deque()

t = 0
ans = 0

def can_go(x, y):
    return 0<=x<n and 0<=y<m and not visited[x][y] and grid[x][y] == 0

def is_glac(x, y):
    return 0<=x<n and 0<=y<m and not visited[x][y] and grid[x][y] == 1

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while water:
        x, y = water.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy
        
            if can_go(nx, ny):
                visited[nx][ny] = True
                water.append((nx, ny))

            elif is_glac(nx, ny):
                visited[nx][ny] = True
                glac.append((nx, ny))

def melt():
    while glac:
        x, y = glac.popleft()
        grid[x][y] = 0

visited[0][0] = True
water.append((0, 0))

while True:
    bfs()

    if not glac:
        break
    
    t += 1
    ans = len(glac)

    water = glac.copy()

    melt()


print(t, ans)