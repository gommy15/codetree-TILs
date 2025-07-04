from collections import deque

n, k, u, d = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

q = deque()
visited = [[False]*n for _ in range(n)]
ans = 0

o_pos = [
    (i, j)
    for i in range(n)
    for j in range(n)
]
selc_pos = []

dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]


def can_go(x, y, h):
    return 0<=x<n and 0<=y<n and not visited[x][y] and u<= abs(grid[x][y] - h) <= d

def bfs():
    global visited

    visited = [[False]*n for _ in range(n)]
    cnt = len(selc_pos)
    
    for pos in selc_pos:
        x, y = pos
        visited[x][y] = True
        q.append(pos)
    
    
    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny, grid[x][y]):
                q.append((nx, ny))
                visited[nx][ny] = True
                cnt += 1

    return cnt



def find_max_area(idx, cnt):
    global ans

    if cnt == k:
        ans = max(ans, bfs())
        return
    
    if idx >= n*n:
        return
    
    selc_pos.append(o_pos[idx])
    find_max_area(idx+1, cnt+1)
    selc_pos.pop()

    find_max_area(idx+1, cnt)

find_max_area(0, 0)

print(ans)