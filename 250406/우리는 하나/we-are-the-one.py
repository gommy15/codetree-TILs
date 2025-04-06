from collections import deque

n, k, u, d = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

ans = 0

s_pos = []
pos = [
    (i, j)
    for i in range(n)
    for j in range(n)
]

q = deque()
visited = [[False for _ in range(n)] for _ in range(n)]

def can_go(x, y, num):
    return 0<=x<n and 0<=y<n and not visited[x][y] and u <= abs(grid[x][y] - num) <= d

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny, grid[x][y]):
                q.append((nx, ny))
                visited[nx][ny] = True

def calc():
    for i in range(n):
        for j in range(n):
            visited[i][j] = 0
    
    for x, y in s_pos:
        q.append((x, y))
        visited[x][y] = True
    
    bfs()

    return sum([
        visited[i][j]
        for i in range(n)
        for j in range(n)
    ])

def find_city(idx, cnt):
    global ans

    if cnt > k:
        return
    
    if idx == n*n:
        if cnt == k:
            ans = max(ans, calc())
        return
    
    s_pos.append(pos[idx])
    find_city(idx+1, cnt+1)
    s_pos.pop()

    find_city(idx+1, cnt)


find_city(0, 0)
print(ans)