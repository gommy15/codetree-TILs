n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

def getCoin(sx, sy, ex, ey):
    cnt = 0

    for x in range(sx, ex+1):
        for y in range(sy, ey+1):
            cnt += grid[x][y]

    return cnt

ans = 0

for i in range(n):
    for j in range(n):
        if i+2>=n or j+2 >=n:
            continue
        
        cnt = getCoin(i, j, i+2, j+2)

        ans = max(ans, cnt)

print(ans)