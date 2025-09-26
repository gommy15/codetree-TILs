n, m, c = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

a = []
max_val = 0

def find_max_sum(idx, w, v):
    global max_val

    if idx == m:
        if w <= c:
            max_val = max(max_val, v)
        return
    
    find_max_sum(idx+1, w, v)

    find_max_sum(idx+1, w+a[idx], v+a[idx]*a[idx])

def find_max(x, y):
    global a, max_val

    a = grid[x][y:y+m]

    max_val = 0
    find_max_sum(0, 0, 0)

    return max_val


def possible(x1, y1, x2, y2):
    if y1+m-1 >= n or y2+m-1 >= n:
        return False
    
    if x1 != x2:
        return True
    
    if not (y1+m-1 < y2 or y2+m-1 < y1):
        return False
    
    return True

ans = max([
    find_max(i, j) + find_max(k, l)
    for i in range(n)
    for j in range(n)
    for k in range(n)
    for l in range(n)
    if possible(i, j, k, l)
])

print(ans)