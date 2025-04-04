n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[False]*m for _ in range(n)]

max_k = max([
    grid[i][j]
    for i in range(n)
    for j in range(m)
])

def can_go(x, y, k):
    return 0<=x<n and 0<=y<m and grid[x][y] > k and not visited[x][y]

def dfs(x, y, k):
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny, k):
            visited[nx][ny] = True
            dfs(nx, ny, k)

ans_k = 0
ans = 0


for k in range(1, max_k+1):
    visited = [[False]*m for _ in range(n)]
    cnt = 0

    for i in range(n):
        for j in range(m):
            if can_go(i, j, k):
                visited[i][j] = True
                dfs(i, j, k)

                cnt += 1
    
    if cnt > ans:
        ans_k = k
        ans = cnt

print(ans_k, ans)