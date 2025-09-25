n = int(input())

lines = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

lines.sort()

selc_line = []

ans = 0

def possible():
    for i in range(1, len(selc_line)):
        _, y = selc_line[i-1]
        x, _ = selc_line[i]

        if y >= x:
            return False
    
    return True

def find_max_line(cnt):
    global ans

    if cnt == len(lines):
        if possible():
            ans = max(ans, len(selc_line))
        return
    
    selc_line.append(lines[cnt])
    find_max_line(cnt + 1)
    selc_line.pop()

    find_max_line(cnt+1)


find_max_line(0)

print(ans)