import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))

spots = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

selc_spot = []
ans = INT_MAX

def calc():
    result = 0

    for i in range(m):
        for j in range(i+1, m):
            a, b = selc_spot[i]
            c, d = selc_spot[j]

            result = max(result, (a-c)**2 + (b-d)**2)
    
    return result

def find_min_dist(idx, cnt):
    global ans

    if cnt == m:
        ans = min(ans, calc())
        return
    
    if idx == n:
        return
    
    selc_spot.append(spots[idx])
    find_min_dist(idx+1, cnt+1)
    selc_spot.pop()

    find_min_dist(idx+1, cnt)


find_min_dist(0, 0)

print(ans)
