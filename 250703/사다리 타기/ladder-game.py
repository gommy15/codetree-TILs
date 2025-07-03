n, m = tuple(map(int, input().split()))

selc_lines = []
lines = []

ans = m

def possible():
    origin = [i for i in range(n)]
    selc_or = [i for i in range(n)]

    for _, idx in lines:
        origin[idx], origin[idx+1] = origin[idx+1], origin[idx]
    
    for _, idx in selc_lines:
        selc_or[idx], selc_or[idx+1] = selc_or[idx+1], selc_or[idx]

    for i in range(n):
        if origin[i] != selc_or[i]:
            return False
    
    return True

def find_min_lines(cnt):
    global ans

    if cnt == m:
        if possible():
            ans = min(ans, len(selc_lines))
        return
    
    selc_lines.append(lines[cnt])
    find_min_lines(cnt+1)
    selc_lines.pop()

    find_min_lines(cnt+1)

for i in range(m):
    a, b = tuple(map(int, input().split()))
    lines.append((b, a-1))

lines.sort()

find_min_lines(0)
print(ans)