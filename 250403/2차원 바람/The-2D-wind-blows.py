n, m, q = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

tmp = [[0 for _ in range(m)] for _ in range(n)]


def rotate(r1, c1, r2, c2):
    tmp_n = grid[r1][c1]

    for r in range(r1, r2):
        grid[r][c1] = grid[r+1][c1]

    for c in range(c1, c2):
        grid[r2][c] = grid[r2][c+1]

    for r in range(r2, r1, -1):
        grid[r][c2] = grid[r-1][c2]
    
    for c in range(c2, c1, -1):
        grid[r1][c] = grid[r1][c-1]

    grid[r1][c1+1] = tmp_n

def inRange(x, y):
    return 0<=x<n and 0<=y<m

def average(x, y):
    dxs, dys = [0, 1, -1, 0, 0], [0, 0, 0, 1, -1]

    nums = [
        grid[x+dx][y+dy]
        for dx, dy in zip(dxs, dys)
        if inRange(x+dx, y+dy)
    ]

    return sum(nums) // len(nums)

def set_average(r1, c1, r2, c2):
    for r in range(r1, r2+1):
        for c in range(c1, c2+1):
            tmp[r][c] = average(r, c)
    
    for r in range(r1, r2+1):
        for c in range(c1, c2+1):
            grid[r][c] = tmp[r][c]

def simulate(r1, c1, r2, c2):
    rotate(r1, c1, r2, c2)

    set_average(r1, c1, r2, c2)


for _ in range(q):
    r1, c1, r2, c2 = tuple(map(int, input().split()))

    simulate(r1-1, c1-1, r2-1, c2-1)

for i in range(n):
    for j in range(m):
        print(grid[i][j], end=" ")
    print()