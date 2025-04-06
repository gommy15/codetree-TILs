from collections import deque

n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

q = deque()
melt_g = deque()
visited = [[False for _ in range(m)] for _ in range(n)]

cnt = 0

dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

t = 0
last_cnt = 0

def can_go(x, y):
    return 0<=x<n and 0<=y<m and grid[x][y] == 0 and not visited[x][y]

def is_glacier(x, y):
    return 0<=x<n and 0<=y<m and grid[x][y] == 1 and not visited[x][y]

def bfs():
    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = True
            elif is_glacier(nx, ny):
                melt_g.append((nx, ny))
                visited[nx][ny] = True


def melt():
    while melt_g:
        x, y = melt_g.popleft()
        grid[x][y] = 0

def simulate():
    global t, last_cnt, q

    bfs()

    if not melt_g:
        return False
    
    t += 1
    last_cnt = len(melt_g)

    q = melt_g.copy()

    melt()

    return True

q.append((0, 0))
visited[0][0] = True

while True:
    is_exist = simulate()

    if not is_exist:
        break

print(t, last_cnt)