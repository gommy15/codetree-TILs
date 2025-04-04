import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))
pos = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

selc_pos = []

ans = INT_MAX

def dist(p1, p2):
    (x1, y1), (x2, y2) = p1, p2
    return (x1-x2)**2 + (y1-y2)**2

def calc():
    return max([
        dist(p1, p2)
        for i, p1 in enumerate(selc_pos)
        for j, p2 in enumerate(selc_pos)
        if i != j
    ])

def find_min(idx, cnt):
    global ans

    if cnt == m:
        ans = min(ans, calc())
        return
    
    if idx == n:
        return

    selc_pos.append(pos[idx])
    find_min(idx+1, cnt+1)
    selc_pos.pop()

    find_min(idx+1, cnt)

find_min(0, 0)
print(ans)