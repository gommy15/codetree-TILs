import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[False]*m for _ in range(n)]
ans_max = 0
ans_k = 1

def can_go(x, y, k):
    return 0<=x<n and 0<=y<m and grid[x][y] > k and not visited[x][y]

def dfs(x, y, k):
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny, k):
            visited[nx][ny] = True
            dfs(nx, ny, k)

for k in range(1, 51):
    visited = [[False]*m for _ in range(n)]
    cnt = 0

    for i in range(n):
        for j in range(m):
            if not visited[i][j] and grid[i][j] > k:
                visited[i][j] = True
                dfs(i, j, k)
                cnt += 1

    if ans_max < cnt:
        ans_max = cnt
        ans_k = k

print(ans_k, ans_max)
