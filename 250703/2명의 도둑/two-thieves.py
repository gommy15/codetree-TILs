n, m, c = tuple(map(int, input().split()))

weight = [
    list(map(int, input().split()))
    for _ in range(n)
]

a = []
ans = 0

def find_max_sum(idx, w, v):
    global ans

    if idx == m:
        if w <= c:
            ans = max(ans, v)
        return

    find_max_sum(idx+1, w, v)

    find_max_sum(idx+1, w+a[idx], v+a[idx]*a[idx])

def find_max(x, y):
    global a, ans

    a = weight[x][y:y+m]

    ans = 0
    find_max_sum(0, 0, 0)
    return ans

def intersect(a, b, c, d):
    return not (b<c or d<a)

def possible(x1, y1, x2, y2):
    if y1+m-1 >= n or y2+m-1 >= n:
        return False
    
    if x1 != x2:
        return True
    
    if intersect(y1, y1+m-1, y2, y2+m-1):
        return False
    
    return True

ans = max([
    find_max(x1, y1) + find_max(x2, y2)
    for x1 in range(n)
    for y1 in range(n)
    for x2 in range(n)
    for y2 in range(n)
    if possible(x1, y1, x2, y2)
])

print(ans)