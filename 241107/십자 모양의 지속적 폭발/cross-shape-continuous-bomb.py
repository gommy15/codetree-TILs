OUT_OF_GRID = -1

n, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]
next_grid = [
    [0 for _ in range(n)]
    for _ in range(n)
]


def in_bomb_range(x, y, center_x, center_y, bomb_range):
    return (x == center_x or y == center_y) and \
           abs(x - center_x) + abs(y - center_y) < bomb_range


def bomb(center_x, center_y):
    for i in range(n):
        for j in range(n):
            next_grid[i][j] = 0
    
    bomb_range = grid[center_x][center_y]
    
    for i in range(n):
        for j in range(n):
            if in_bomb_range(i, j, center_x, center_y, bomb_range):
                grid[i][j] = 0


    for j in range(n):
        next_row = n - 1
        for i in range(n - 1, -1, -1):
            if grid[i][j]:
                next_grid[next_row][j] = grid[i][j]
                next_row -= 1
                

    for i in range(n):
        for j in range(n):
            grid[i][j] = next_grid[i][j]


def get_bomb_row(col):
    for row in range(n):
        if grid[row][col] != 0:
            return row
    
    return OUT_OF_GRID


for _ in range(m):
    bomb_col = int(input()) - 1

    bomb_row = get_bomb_row(bomb_col)

    if bomb_row == OUT_OF_GRID:
        continue

    bomb(bomb_row, bomb_col)

for i in range(n):
    for j in range(n):
        print(grid[i][j], end=" ")
    print()