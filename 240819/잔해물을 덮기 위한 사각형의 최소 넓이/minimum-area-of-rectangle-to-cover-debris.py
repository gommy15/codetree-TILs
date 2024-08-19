OFFSET = 1000
MAX_R = 2000

rects = [
    tuple(map(int, input().split()))
    for _ in range(2)
]

checked = [
    [0] * (MAX_R+1)
    for _ in range(MAX_R+1)
]

for i, (x1, y1, x2, y2) in enumerate(rects, start = 1):
    x1, y1 = x1+OFFSET, y1+OFFSET
    x2, y2 = x2+OFFSET, y2+OFFSET

    for x in range(x1, x2):
        for y in range(y1, y2):
            checked[x][y] = i

x1, y1, x2, y2 = MAX_R, MAX_R, 0, 0
rect_exist = False

for x in range(MAX_R+1):
    for y in range(MAX_R+1):
        if checked[x][y] == 1:
            rect_exist = True
            x1 = min(x1, x)
            y1 = min(y1, y)
            x2 = max(x2, x)
            y2 = max(y2, y)

if rect_exist:
    print((x2-x1+1)*(y2-y1+1))
else:
    print(0)