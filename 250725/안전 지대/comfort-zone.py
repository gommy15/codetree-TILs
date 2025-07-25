n, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

max_k = max([max(g) for g in grid])
visited = [[False]*m for _ in range(n)]

ans_k = 1
ans_area = 0

def can_go(x, y, k):
    return 0<=x<n and 0<=y<m and not visited[x][y] and grid[x][y] > k

def dfs(x, y, k):
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny, k):
            visited[nx][ny] = True
            dfs(nx, ny, k)

for k in range(1, max_k):
    cnt = 0
    visited = [[False]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and grid[i][j] > k:
                visited[i][j] = True
                cnt += 1
                dfs(i, j, k)
    
    if ans_area < cnt:
        ans_area = cnt
        ans_k = k

print(ans_k, ans_area)