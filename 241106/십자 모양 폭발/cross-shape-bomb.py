n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

def inRange(x, y):
    return 0<=x<n and 0<=y<n

def bumb(x, y):
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]
    ran = grid[x][y]

    for k in range(ran):
        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx*k, y+dy*k

            if inRange(nx, ny):
                grid[nx][ny] = 0

def gravity():
    tmp = [[0 for _ in range(n)] for _ in range(n)]

    
    for col in range(n):
        idx = n-1
        for row in range(n-1, -1, -1):
            if grid[row][col] == 0:
                continue
            tmp[idx][col] = grid[row][col]

            idx -= 1
    

    for i in range(n):
        for j in range(n):
            grid[i][j] = tmp[i][j]


r, c = tuple(map(int, input().split()))

bumb(r-1, c-1)
gravity()

for i in range(n):
    for j in range(n):
        print(grid[i][j], end = " ")
    
    print()