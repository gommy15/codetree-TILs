n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

next_grid = [[0 for _ in range(n)] for _ in range(n)]

tmp = [[0 for _ in range(n)] for _ in range(n)]

ans = 0

def isPossible(x, y, cx, cy, br):
    return (x == cx or y==cy) and abs(x-cx) + abs(y-cy) < br

def bomb(x, y):
    global grid, next_grid

    for i in range(n):
        for j in range(n):
            next_grid[i][j] = 0
    
    bomb_range = grid[x][y]

    for i in range(n):
        for j in range(n):
            if isPossible(i, j, x, y, bomb_range):
                grid[i][j] = 0
    
    for j in range(n):
        next_r = n-1
        for i in range(n-1, -1, -1):
            if grid[i][j]:
                next_grid[next_r][j] = grid[i][j]
                next_r -= 1

    grid = next_grid

def meet_condition(x, y, nx, ny):
    return 0<=nx<n and 0<=ny<n and grid[x][y] and grid[x][y] == grid[nx][ny]

def calc():
    cnt = 0

    dxs, dys = [-1, 1, 0, 0], [0, 0, 1, -1]

    for x in range(n):
        for y in range(n):
            for dx, dy in zip(dxs, dys):
                nx, ny = x+dx, y+dy

                if meet_condition(x, y, nx, ny):
                    cnt += 1
    
    return cnt//2


for i in range(n):
    for j in range(n):
        tmp = grid
        bomb(i, j)
        ans = max(ans, calc())
        grid = tmp

print(ans)
