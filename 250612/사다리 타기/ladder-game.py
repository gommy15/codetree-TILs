n, m = tuple(map(int, input().split()))

lines = []
selc_lines = []

ans = m

for _ in range(m):
    a, b = tuple(map(int, input().split()))
    lines.append((b, a-1))

lines.sort()


def possible():
    num1, num2 = [i for i in range(n)], [i for i in range(n)]

    for _, idx in lines:
        num1[idx], num1[idx+1] = num1[idx+1], num1[idx]
    
    for _, idx in selc_lines:
        num2[idx], num2[idx+1] = num2[idx+1], num2[idx]
    
    return all(num1[i] == num2[i] for i in range(n))


def find_min_lines(cnt):
    if cnt == m:
        if possible():
            global ans

            ans = min(ans, len(selc_lines))
        
        return
    
    selc_lines.append(lines[cnt])
    find_min_lines(cnt+1)
    selc_lines.pop()

    find_min_lines(cnt+1)

find_min_lines(0)

print(ans)