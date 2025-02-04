from collections import deque

n, k, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

ans = 0
stone_spot = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if grid[i][j] == 1
]

start_pos = []
selec_stone = []

q = deque()
visited = [[0 for _ in range(n)] for _ in range(n)]

def can_go(x, y):
    return 0<=x<n and 0<=y<n and not visited[x][y] and not grid[x][y]

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = 1


def calc():
    for x, y in selec_stone:
        grid[x][y] = 0
    
    for i in range(n):
        for j in range(n):
            visited[i][j] = 0

    for x, y in start_pos:
        q.append((x, y))
        visited[x][y] = 1

    bfs()

    for x, y in selec_stone:
        grid[x][y] = 1
    

    return sum([
        visited[i][j]
        for i in range(n)
        for j in range(n)
    ])

def find_max(idx, cnt):
    global ans

    if idx == len(stone_spot):
        if cnt == m:
            ans = max(ans, calc())
        
        return
    
    selec_stone.append(stone_spot[idx])
    find_max(idx+1, cnt+1)
    selec_stone.pop()

    find_max(idx+1, cnt)


for _ in range(k):
    r, c = tuple(map(int, input().split()))
    
    start_pos.append((r-1, c-1))


find_max(0, 0)
print(ans)