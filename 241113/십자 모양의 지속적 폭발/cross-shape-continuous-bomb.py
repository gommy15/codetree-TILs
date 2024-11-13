n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

next_grid = [[0 for _ in range(n)] for _ in range(n)]

def exploded(x, y):
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]
    length = grid[x][y]

    for l in range(length):
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx*l, y+dy*l

            if 0<=nx<n and 0<=ny<n:
                grid[nx][ny] = 0

def bumb(c):
    for i in range(n):
        if grid[i][c]:
            exploded(i, c)

            return True
    
    return False

def gravity():
    for i in range(n):
        for j in range(n):
            next_grid[i][j] = 0
    
    for j in range(n):
        idx = n-1
        for i in range(n-1, -1, -1):
            if grid[i][j]:
                next_grid[idx][j] = grid[i][j]

                idx -= 1
    
    for i in range(n):
        for j in range(n):
            grid[i][j] = next_grid[i][j]

while m:
    m -= 1
    c = int(input())

    exist = False

    exist = bumb(c-1)

    if exist:
        gravity()

for i in range(n):
    for j in range(n):
        print(grid[i][j], end=" ")
    print()