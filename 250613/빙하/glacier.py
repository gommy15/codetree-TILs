from collections import deque

n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

q = deque()
melting = deque()
visited = [[False]*m for _ in range(n)]

cnt = 0

dxs, dys = [0, 1, 0, -1], [1, 0, -1, 0]

total_t = 0
last_melt = 0

q.append((0, 0))
visited[0][0] = True

def can_go(x, y):
    return 0<=x<n and 0<=y<m and grid[x][y] == 0 and not visited[x][y]

def is_glac(x, y):
    return 0<=x<n and 0<=y<m and grid[x][y] == 1 and not visited[x][y]

def bfs():
    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = True
            elif is_glac(nx, ny):
                melting.append((nx, ny))
                visited[nx][ny] = True

def melt():
    while melting:
        x, y = melting.popleft()
        grid[x][y] = 0

def simulate():
    global total_t, last_melt, q

    bfs()

    if not melting:
        return False
    
    total_t += 1
    last_melt = len(melting)
    
    q = melting.copy()

    melt()

    return True

while True:
    is_exist = simulate()

    if not is_exist:
        break

print(total_t, last_melt)