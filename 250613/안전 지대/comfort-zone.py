import sys
sys.setrecursionlimit(2500)

n, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [
    [False for _ in range(m)]
    for _ in range(n)
]

zone_num = 0

def can_go(x, y, k):
    return 0<=x<n and 0<=y<m and grid[x][y] > k and not visited[x][y]

def dfs(x, y, k):
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny, k):
            visited[nx][ny] = True
            dfs(nx, ny, k)

def get_zone_num(k):
    global zone_num, visited

    zone_num = 0

    visited = [[False]*m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if can_go(i, j, k):
                visited[i][j] = True
                zone_num += 1

                dfs(i, j, k)


max_zone = -1
ans_k = 0
max_h = 100

for k in range(1, max_h+1):
    get_zone_num(k)

    if zone_num > max_zone:
        max_zone, ans_k = zone_num, k

print(ans_k, max_zone)