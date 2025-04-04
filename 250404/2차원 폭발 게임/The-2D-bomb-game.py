BLANK = -1
WILL_EXPLODE = 0

n, m, k = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

tmp_arr = [0] * n

def copy_col(c):
    global tmp_arr

    tmp_arr = [
        grid[r][c]
        for r in range(n)
        if grid[r][c] != BLANK
    ]

def get_idx_exploded(idx, num):
    for end_idx in range(idx+1, len(tmp_arr)):
        if tmp_arr[end_idx] != num:
            return end_idx-1
    
    return len(tmp_arr) - 1

def explode():
    while True:
        did_exploded = False
        cur_idx = 0

        while cur_idx < len(tmp_arr):
            end_idx = get_idx_exploded(cur_idx, tmp_arr[cur_idx])

            if end_idx - cur_idx + 1 >= m:
                del tmp_arr[cur_idx:end_idx+1]
                did_exploded = True
            else:
                cur_idx = end_idx+1

        if not did_exploded:
            break

def copy_result(c):
    for r in range(n-1, -1, -1):
        grid[r][c] = tmp_arr.pop() if tmp_arr else BLANK

def simulate():
    for c in range(n):
        copy_col(c)
        explode()
        copy_result(c)

def rotate():
    global grid

    tmp = [[BLANK for _ in range(n)] for _ in range(n)]

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

answer = sum([
    grid[i][j] != BLANK
    for i in range(n)
    for j in range(n)
])

print(answer)
