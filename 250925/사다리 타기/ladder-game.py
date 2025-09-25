n, m = tuple(map(int, input().split()))

lines = [
    tuple(map(int, input().split()))
    for _ in range(m)
]

lines = [(b, a) for a, b in lines]
selc_line = []

lines.sort()
ans = len(lines)

def possible():
    orig = [i for i in range(n+1)]
    tmp = [i for i in range(n+1)]

    for _, a in lines:
        orig[a], orig[a+1] = orig[a+1], orig[a]

    for _, a in selc_line:
        tmp[a], tmp[a+1] = tmp[a+1], tmp[a]
    
    return all(orig[i] == tmp[i] for i in range(1, n+1))

def find_min_line(cnt):
    global ans

    if cnt == len(lines):
        if possible():
            ans = min(ans, len(selc_line))
        
        return
    
    selc_line.append(lines[cnt])
    find_min_line(cnt+1)
    selc_line.pop()

    find_min_line(cnt+1)



find_min_line(0)

print(ans)