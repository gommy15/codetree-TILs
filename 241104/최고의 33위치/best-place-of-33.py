n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

ans = 0

for i in range(n):
    for j in range(n):
        if i+2 >= n or j+2>= n:
            continue
        cnt = 0
        for a in range(3):
            for b in range(3):
                cnt += grid[i+a][j+b]
        
        ans = max(ans, cnt)

print(ans)