OFFSET = 100
MAX_R = 200

n = int(input())

checked = [
    [0] * (MAX_R+1)
    for _ in range(MAX_R+1)
]

for _ in range(n):
    x1, y2 = tuple(map(int, input().split()))
    x1, y1 = x1+OFFSET, y2+OFFSET-8
    x2, y2 = x1+8, y2+OFFSET

    for x in range(x1, x2):
        for y in range(y1, y2):
            checked[x][y] = 1

ans = 0
for x in range(MAX_R+1):
    for y in range(MAX_R+1):
        if checked[x][y]:
            ans += 1

print(ans)