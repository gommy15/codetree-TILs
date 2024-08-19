OFFSET = 1000
MAX_R = 2000

rects = [
    tuple(map(int, input().split()))
    for _ in range(3)
]

checked = [
    [0] * (MAX_R+1)
    for _ in range(MAX_R+1)
]

cnt = 1
for x1, y1, x2, y2 in rects:
    x1, y1 = x1+OFFSET, y1+OFFSET
    x2, y2 = x2+OFFSET, y2+OFFSET

    for x in range(x1, x2):
        for y in range(y1, y2):
            if cnt != 3:
                checked[x][y] = 1
            else:
                checked[x][y] = 0
    
    cnt += 1

ans = 0

for x in range(MAX_R+1):
    for y in range(MAX_R+1):
        if checked[x][y]:
            ans += 1

print(ans)