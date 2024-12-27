n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

ans = 0

for i in range(n):
    for j in range(n):
        if i+2 >=n or j+2 >=n:
            continue
        
        cnt = 0
        for x in range(i, i+3):
            for y in range(j, j+3):
                cnt += grid[x][y]
        
        ans = max(ans, cnt)


print(ans)