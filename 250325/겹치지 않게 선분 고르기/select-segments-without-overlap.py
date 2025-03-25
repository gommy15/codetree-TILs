n = int(input())

lines = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

lines.sort()
selc_line = []
ans = 0

def check():
    for i in range(1, len(selc_line)):
        x1, y1 = selc_line[i-1]
        x2, y2 = selc_line[i]

        if x2 <= y1: 
            return False
    
    return True

def findMaxLine(idx):
    if idx == len(lines):
        if check():
            global ans

            ans = max(ans, len(selc_line))
        return
    
    selc_line.append(lines[idx])
    findMaxLine(idx+1)
    selc_line.pop()

    findMaxLine(idx+1)


findMaxLine(0)

print(ans)