from collections import deque

n, k, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

ans = 0
s_pos = []
stone_pos = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if grid[i][j] == 1
]

selected_stones = []

q = deque()
visited = [
    [0 for _ in range(n)]
    for _ in range(n)
]

def canGo(x, y):
    return 0<=x<n and 0<=y<n and grid[x][y] == 0 and not visited[x][y]

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if canGo(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = 1

def Calc():
    for x, y in selected_stones:
        grid[x][y] = 0
    
    for i in range(n):
        for j in range(n):
            visited[i][j] = 0

    for x, y in s_pos:
        q.append((x, y))
        visited[x][y] = 1
    
    bfs()

    for x, y in selected_stones:
        grid[x][y] = 1

    cnt = 0
    for i in range(n):
        for j in range(n):
            if visited[i][j]:
                cnt += 1
    
    return cnt

def find_max(idx, cnt):
    global ans

    if idx == len(stone_pos):
        if cnt == m:
            ans = max(ans, Calc())
        return
    
    selected_stones.append(stone_pos[idx])
    find_max(idx+1, cnt+1)
    selected_stones.pop()

    find_max(idx+1, cnt)

for _ in range(k):
    r, c = tuple(map(int, input().split()))
    s_pos.append((r-1, c-1))

find_max(0, 0)
print(ans)