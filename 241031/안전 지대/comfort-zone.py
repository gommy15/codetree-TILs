n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]


def inRange(x, y):
    return 0<=x and x<n and 0<=y and y<m

def canGo(x, y, k, visited):
    if not inRange(x, y):
        return False
    if grid[x][y] <= k or visited[x][y]:
        return False
    
    return True


def dfs(x, y, k, visited):
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if canGo(nx, ny, k, visited):
            visited[nx][ny] = 1
            dfs(nx, ny, k, visited)


ans = 0
ans_k = 0

max_k = max(max(row) for row in grid)

for k in range(max_k+1):
    cnt = 0
    visited = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if canGo(i, j, k, visited):
                cnt += 1
                visited[i][j] = 1
                dfs(i, j, k, visited)

    if ans < cnt:
        ans = cnt
        ans_k = k


print(ans, ans_k)