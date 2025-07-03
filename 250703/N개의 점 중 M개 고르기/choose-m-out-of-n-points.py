import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))

pos = [
    tuple(map(int, input().split()))
    for _ in range(n)
]
selc_pos = []

ans = INT_MAX

def calc():
    tmp = selc_pos.copy()

    tmp.sort()

    x1, y1 = tmp[0]
    x2, y2 = tmp[-1]

    return abs(x2-x1)**2 + abs(y2-y1)**2

def find_min_dist(idx):
    global ans
    
    if len(selc_pos) == m:
        ans = min(ans, calc())
        return
    
    if idx == n:
        return
    
    selc_pos.append(pos[idx])
    find_min_dist(idx+1)
    selc_pos.pop()

    find_min_dist(idx+1)

find_min_dist(0)
print(ans)