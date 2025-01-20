BLANK = -1
WILL_EXPLODE = 0

n, m, k = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

tmp_arr = [0]*n

def copy_col(col):
    global tmp_arr

    tmp_arr = [
        grid[i][col]
        for i in range(n)
        if grid[i][col] != BLANK
    ]

def copy_res(col):
    for row in range(n-1, -1, -1):
        grid[row][col] = tmp_arr.pop() if tmp_arr else BLANK

def get_end_idx(start_idx, cur_num):
    for end_idx in range(start_idx+1, len(tmp_arr)):
        if tmp_arr[end_idx] != cur_num:
            return end_idx - 1
    
    return len(tmp_arr) -1

def explode():
    while True:
        did_explode = False
        cur_idx = 0

        while cur_idx < len(tmp_arr):
            end_idx = get_end_idx(cur_idx, tmp_arr[cur_idx])

            if end_idx - cur_idx + 1 >= m:
                del tmp_arr[cur_idx:end_idx+1]
                did_explode = True
            else:
                cur_idx = end_idx + 1
        
        if not did_explode:
            break

def simulate():
    for col in range(n):
        copy_col(col)
        explode()
        copy_res(col)

def rotate():
    global grid

    tmp = [
        [BLANK for _ in range(n)]
        for _ in range(n)
    ]

    for i in range(n-1, -1, -1):
        cur_idx = n-1
        for j in range(n-1, -1, -1):
            if grid[i][j] != BLANK:
                tmp[cur_idx][n-i-1] = grid[i][j]
                cur_idx -= 1
    
    grid = tmp

simulate()
for _ in range(k):
    rotate()
    simulate()

ans = sum([
    grid[i][j] != BLANK
    for i in range(n)
    for j in range(n)
])

print(ans)