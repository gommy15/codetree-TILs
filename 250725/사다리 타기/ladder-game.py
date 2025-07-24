

n, m = tuple(map(int, input().split()))

lines = [
    tuple(map(int, input().split()))
    for _ in range(m)
]
selc_lines = []

lines = [(b, a) for a, b in lines]
lines.sort()

ans = m

def check():
    orig = [i for i in range(1, n+1)]
    tmp = [i for i in range(1, n+1)]

    for _, a in lines:
        orig[a-1], orig[a] = orig[a], orig[a-1]
    
    for _, a in selc_lines:
        tmp[a-1], tmp[a] = tmp[a], tmp[a-1]

    
    for i in range(n):
        if orig[i] != tmp[i]:
            return False
    
    return True

def find_min_lines(idx):
    global ans
    
    if idx == m:
        if check():
            ans = min(ans, len(selc_lines))
        
        return
    
    selc_lines.append(lines[idx])
    find_min_lines(idx+1)
    selc_lines.pop()

    find_min_lines(idx+1)


find_min_lines(0)
print(ans)