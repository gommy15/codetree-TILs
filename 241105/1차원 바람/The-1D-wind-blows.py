SHIFT_LEFT = 1
SHIFT_RIGHT = 0

n, m, q = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

def shift(row, direc):
    if direc == SHIFT_RIGHT:
        grid[row].insert(0, grid[row].pop())
    else:
        grid[row].insert(m-1, grid[row].pop(0))

def same_num(row1, row2):
    return any([
        grid[row1][col] == grid[row2][col]
        for col in range(m)
    ])

def flip(curr_dir):
    return SHIFT_LEFT if curr_dir == SHIFT_RIGHT else SHIFT_RIGHT
    

def simulate(sr, d):
    shift(sr, d)

    d = flip(d)

    curr_dir = d
    for r in range(sr, 0, -1):
        if same_num(r, r-1):
            shift(r-1, curr_dir)
            curr_dir = flip(curr_dir)
        else:
            break
    
    curr_dir = d
    for r in range(sr, n-1):
        if same_num(r, r+1):
            shift(r+1, curr_dir)
            curr_dir = flip(curr_dir)
        else:
            break


while q:
    q -= 1

    r, d = tuple(input().split())
    r = int(r)

    simulate(r-1, SHIFT_RIGHT if d == 'L' else SHIFT_LEFT)

for i in range(n):
    for j in range(m):
        print(grid[i][j], end=" ")
    print()