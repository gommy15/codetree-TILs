import sys

COIN_NUM = 9
INT_MAX = sys.maxsize

n = int(input())
m = 3

grid = [
    input()
    for _ in range(n)
]

coin_pos = []
selc_pos = []

s_pos = (-1, -1)
e_pos = (-1, -1)

ans = INT_MAX

for i in range(n):
    for j in range(n):
        if grid[i][j] == 'S':
            s_pos = (i, j)
        if grid[i][j] == 'E':
            e_pos = (i, j)

for c in range(1, COIN_NUM+1):
    for i in range(n):
        for j in range(n):
            if grid[i][j] == str(c):
                coin_pos.append((i, j))


def dist(a, b):
    ax, ay, bx, by = a, b

    return abs(ax-bx) + abs(ay-by)

def calc():
    moves = dist(s_pos, selc_pos[0])

    for i in range(m-1):
        moves += dist(selc_pos[i], selc_pos[i+1])
    
    moves += dist(selc_pos[m-1], e_pos)

    return moves

def find_min_moves(idx, cnt):
    global ans

    if cnt == m:
        ans = min(ans, calc())
        return
    
    if idx == len(coin_pos):
        return
    
    find_min_moves(idx+1, cnt)

    selc_pos.append(coin_pos[idx])
    find_min_moves(idx+1, cnt+1)
    selc_pos.pop()


find_min_moves(0, 0)

print(ans)

