n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[False for _ in range(m)] for _ in range(n)]

dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

def inRange(x, y):
    return 0<=x<n and 0<=y<m

def can_go(x, y, k):
    if not inRange(x, y):
        return False
    if visited[x][y] or grid[x][y] <= k:
        return False
    
    return True

def dfs(x, y, k):
    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy
        
        if can_go(nx, ny, k):
            visited[nx][ny] = True
            dfs(nx, ny, k)

ans, ans_k = -1, 0

for k in range(1, 101):
    cnt = 0
    for i in range(n):
        for j in range(m):
            visited[i][j] = False
    
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and grid[i][j] > k:
                dfs(i, j, k)
                cnt += 1
    
    if ans < cnt:
        ans, ans_k = cnt, k

print(ans, ans_k)