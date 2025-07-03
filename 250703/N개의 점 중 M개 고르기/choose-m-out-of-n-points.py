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
    result = 0

    for i in range(m):
        for j in range(i+1, m):
            x1, y1 = selc_pos[i]
            x2, y2 = selc_pos[j]

            result = max(result, abs(x2-x1)**2 + abs(y2-y1)**2)

    return result

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