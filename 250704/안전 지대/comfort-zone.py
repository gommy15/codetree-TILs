import sys
sys.setrecursionlimit(2500)

n, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

MAX_K = max([
    grid[i][j]
    for i in range(n)
    for j in range(m)
])

visited = [[False]*m for _ in range(n)]

safe_area = 0
max_area = 0
ans_k = 0

def can_go(x, y, k):
    return 0<=x<n and 0<=y<m and not visited[x][y] and grid[x][y] > k

def dfs(x, y, k):
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny, k):
            visited[nx][ny] = True
            dfs(nx, ny, k)


for k in range(1, MAX_K+1):
    visited = [[False]*m for _ in range(n)]
    safe_area = 0

    for i in range(n):
        for j in range(m):
            if visited[i][j] == False and grid[i][j] > k:
                visited[i][j] = True
                dfs(i, j, k)
                safe_area += 1
    
    if max_area < safe_area:
        ans_k = k
        max_area = safe_area

print(ans_k, max_area)