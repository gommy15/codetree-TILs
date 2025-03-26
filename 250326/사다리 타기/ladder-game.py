n, m = tuple(map(int, input().split()))

lines = []
selc_line = []

ans = m

def possible():
    num1, num2 = [i for i in range(n)], [i for i in range(n)]

    for _, idx in lines:
        num1[idx], num1[idx+1] = num1[idx+1], num1[idx]
    
    for _, idx in selc_line:
        num2[idx], num2[idx+1] = num2[idx+1], num2[idx]

    for i in range(n):
        if num1[i] != num2[i]:
            return False
    
    return True


def findMinLine(cnt):
    global ans

    if cnt == m:
        if possible():
            ans = min(ans, len(selc_line))
        return
    
    selc_line.append(lines[cnt])
    findMinLine(cnt + 1)
    selc_line.pop()

    findMinLine(cnt + 1)

for _ in range(m):
    a, b = tuple(map(int, input().split()))
    lines.append((b, a-1))

lines.sort()

findMinLine(0)

print(ans)