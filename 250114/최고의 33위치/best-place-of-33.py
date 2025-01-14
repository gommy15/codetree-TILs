n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

ans = 0

def cntCoin(x, y):
    cnt = 0

    for i in range(3):
        for j in range(3):
            if i+x >= n or j+y >= n:
                continue
            
            cnt += grid[x+i][y+j]
    
    return cnt

for i in range(n):
    for j in range(n):
        ans = max(ans, cntCoin(i, j))

print(ans)