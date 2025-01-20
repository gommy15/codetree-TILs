n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

def explode(col):
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]
    exist = False

    for i in range(n):
        if grid[i][col]:
            area = grid[i][col]
            
            for a in range(area):
                exist = True
                for dx, dy in zip(dxs, dys):
                    nx, ny = i+dx*a, col+dy*a

                    if 0<=nx<n and 0<=ny<n:
                        grid[nx][ny] = 0
    
    return exist

def gravitiy():
    next_grid = [[0 for _ in range(n)] for _ in range(n)]
    
    for j in range(n):
        idx = n-1
        for i in range(n-1, -1, -1):
            if grid[i][j]:
                next_grid[idx][j] = grid[i][j]
                idx -= 1
    
    for i in range(n):
        for j in range(n):
            grid[i][j] = next_grid[i][j]



while True:
    if m == 0:
        break
    
    c = int(input())

    exist = explode(c-1)

    if exist:
        gravitiy()

    m -= 1

for i in range(n):
    for j in range(n):
        print(grid[i][j], end=" ")
    print()