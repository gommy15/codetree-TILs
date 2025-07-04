from collections import deque

n, k, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

s_pos = []
for _ in range(k):
    r, c  = tuple(map(int, input().split()))
    s_pos.append((r-1, c-1))

stone_pos = []
selc_pos = []

for i in range(n):
    for j in range(n):
        if grid[i][j]:
            stone_pos.append((i, j))

visited = [[False]*n for _ in range(n)]
q = deque()

ans = 0

def can_go(x, y):
    return 0<=x<n and 0<=y<n and not visited[x][y] and not grid[x][y]

def bfs():
    global visited

    visited = [[False]*n for _ in range(n)]
    cnt = len(s_pos)

    for pos in s_pos:
        q.append(pos)
        x, y = pos
        visited[x][y] = True
    
    for pos in selc_pos:
        x, y = pos
        grid[x][y] = 0

    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                q.append((nx, ny))
                visited[nx][ny] = True
                cnt += 1


    for pos in selc_pos:
        x, y = pos
        grid[x][y] = 1

    return cnt

def find_max_cnt(idx, cnt):
    global ans

    if cnt == m:
        ans = max(ans, bfs())
        return

    if idx >= len(stone_pos):
        return

    selc_pos.append(stone_pos[idx])
    find_max_cnt(idx+1, cnt+1)
    selc_pos.pop()

    find_max_cnt(idx+1, cnt)


find_max_cnt(0, 0)

print(ans)