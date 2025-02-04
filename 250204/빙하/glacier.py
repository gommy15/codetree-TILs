from collections import deque

n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

q = deque()
melt_spot = deque()
visited = [[False for _ in range(m)] for _ in range(n)]
cnt = 0

dxs, dys = [0, 1, 0, -1], [1, 0, -1, 0]

elapsed_time = 0
last_melt = 0

def can_go(x, y):
    return 0<=x<n and 0<=y<m and not grid[x][y] and not visited[x][y]

def is_glacier(x, y):
    return 0<=x<n and 0<=y<m and grid[x][y] and not visited[x][y]


def bfs():
    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = True
            elif is_glacier(nx, ny):
                melt_spot.append((nx, ny))
                visited[nx][ny] = True

def melt():
    while melt_spot:
        x, y = melt_spot.popleft()
        grid[x][y] = 0

def simulate():
    global elapsed_time, last_melt, q

    bfs()

    if not melt_spot:
        return False
    
    elapsed_time += 1
    last_melt = len(melt_spot)

    q = melt_spot.copy()

    melt()

    return True

q.append((0, 0))
visited[0][0] = True

while True:
    is_exist = simulate()

    if not is_exist:
        break
    
print(elapsed_time, last_melt)