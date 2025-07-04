from collections import deque

n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[False]*m for _ in range(n)]
water_q = deque()
after_melt = deque()
ans_t = 0
last_melt_cnt = 0

dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

def can_go(x, y):
    return 0<=x<n and 0<=y<m and not visited[x][y] and not grid[x][y]

def is_glac(x, y):
    return 0<=x<n and 0<=y<m and not visited[x][y] and grid[x][y]

def bfs():
    while water_q:
        x, y = water_q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                visited[nx][ny] = True
                water_q.append((nx, ny))
            elif is_glac(nx, ny):
                visited[nx][ny] = True
                after_melt.append((nx, ny))

def melt():
    while after_melt:
        x, y = after_melt.popleft()
        grid[x][y] = 0


def simulate():
    global ans_t, last_melt_cnt, water_q

    bfs()

    if not after_melt:
        return False

    ans_t += 1
    last_melt_cnt = len(after_melt)

    water_q = after_melt.copy()

    melt()

    return True


water_q.append((0, 0))
visited[0][0] = True

while True:
    is_exist = simulate()

    if not is_exist:
        break

print(ans_t, last_melt_cnt)
