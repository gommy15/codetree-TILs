from collections import deque

n, k, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

rocks = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if grid[i][j] == 1
]

s_pos = [
    tuple(map(int, input().split()))
    for _ in range(k)
]

selc_rock = []

visited = [[False]*n for _ in range(n)]
q = deque()
area = 0
ans = 0

def can_go(x, y):
    return 0<=x<n and 0<=y<n and grid[x][y] == 0 and not visited[x][y]

def bfs():
    global area

    for x, y in s_pos:
        q.append((x-1, y-1))
        visited[x-1][y-1] = True
        area += 1
    
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                visited[nx][ny] = True
                q.append((nx, ny))
                area += 1


def find_max_area(idx, cnt):
    global ans, area

    if idx == len(rocks):
        if cnt == m:
            for x, y in selc_rock:
                grid[x][y] = 0

            visited = [[False]*n for _ in range(n)]
            area = 0

            bfs()
            
            for x, y in selc_rock:
                grid[x][y] = 1
            
            ans = max(ans, area)
        return

    selc_rock.append(rocks[idx])
    find_max_area(idx+1, cnt+1)
    selc_rock.pop()

    find_max_area(idx+1, cnt)


find_max_area(0, 0)

print(ans)
