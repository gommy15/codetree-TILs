OUT_OF_GRID = (-1, -1)

n, m, x, y = tuple(map(int, input().split()))
grid = [[0 for _ in range(n)] for _ in range(n)]
movement = input().split()

up, front, right = 1, 2, 3


def next_pos(x, y, move_dir):
    dxs, dys = [0, 0, -1, 1], [1, -1, 0, 0]

    nx, ny = x+dxs[move_dir], y+dys[move_dir]
    return (nx, ny) if 0<=nx<n and 0<=ny<n else OUT_OF_GRID


def simulate(move_dir):
    global x, y, up, front, right

    nx, ny = next_pos(x, y, move_dir)

    if (nx, ny) == OUT_OF_GRID:
        return

    x, y = nx, ny
    
    if move_dir == 0:
        up, front, right = 7-right, front, up
    elif move_dir == 1:
        up, front, right = right, front, 7-up
    elif move_dir == 2:
        up, front, right = front, 7-up, right
    else:
        up, front, right = 7-front, up, right

    bottom = 7-up
    grid[x][y] = bottom


x -= 1
y -= 1

dir_mapper = {
    'R':0,
    'L':1,
    'U':2,
    'D':3
}

grid[x][y] = 6
for char_dir in movement:
    simulate(dir_mapper[char_dir])

ans = sum([
    grid[i][j]
    for i in range(n)
    for j in range(n)
])

print(ans)