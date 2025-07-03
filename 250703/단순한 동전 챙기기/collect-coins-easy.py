import sys

COIN_NUM = 9
INT_MAX = sys.maxsize

n = int(input())
m = 3

grid = [
    input()
    for _ in range(n)
]

coin_pos = [
    (i, j)
    for num in range(1, COIN_NUM+1)
    for i in range(n)
    for j in range(n)
    if grid[i][j] == str(num)
]
start_pos = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if grid[i][j] == 'S'
][0]

end_pos = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if grid[i][j] == 'E'
][0]

selc_pos = []

ans = INT_MAX

def dist(a, b):
    (x1, y1), (x2, y2) = a, b
    return abs(x2-x1) + abs(y2-y1)

def calc():
    num_moves = dist(start_pos, selc_pos[0])
    for i in range(m-1):
        num_moves += dist(selc_pos[i], selc_pos[i+1])
    num_moves += dist(selc_pos[m-1], end_pos)

    return num_moves

def find_min_move(idx, cnt):
    global ans

    if cnt == m:
        ans = min(ans, calc())
        return
    
    if idx == len(coin_pos):
        return
    
    find_min_move(idx+1, cnt)

    selc_pos.append(coin_pos[idx])
    find_min_move(idx+1, cnt+1)
    selc_pos.pop()


find_min_move(0, 0)
print(ans if ans != INT_MAX else -1)