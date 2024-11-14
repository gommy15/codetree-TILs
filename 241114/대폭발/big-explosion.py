n, m, r, c = tuple(map(int, input().split()))

grid = [[0]*n for _ in range(n)]
bomb = []

grid[r-1][c-1] = 1
bomb.append((r-1, c-1))

def make_bomb(t):
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]
    tmp_bomb = []

    for x, y in bomb:
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx*t, y+dy*t

            if 0<=nx<n and 0<=ny<n and grid[nx][ny] == 0:
                grid[nx][ny] = 1
                tmp_bomb.append((nx, ny))
    
    for x, y in tmp_bomb:
        bomb.append((x, y))

t = 1
for _ in range(m):
    make_bomb(t)
    t *= 2

ans = 0
for arr in grid:
    ans += sum(arr)

print(ans)