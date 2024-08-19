OFFSET = 100
MAX_R = 200

n = int(input())
rects = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

checked = [
    [0] * (MAX_R+1)
    for _ in range(MAX_R+1)
]

for x1, y1, x2, y2 in rects:
    x1, y1 = x1+OFFSET, y1+OFFSET
    x2, y2 = x2+OFFSET, y2+OFFSET

    for x in range(x1, x2):
        for y in range(y1, y2):
            checked[x][y] = 1


area = 0

for x in range(0, MAX_R+1):
    for y in range(0, MAX_R+1):
        if checked[x][y]:
            area += 1


print(area)