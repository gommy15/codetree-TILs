n, m, k = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

k -= 1

for r in range(n):
    exist = False
    for c in range(k, k+m):
        if grid[r][c] == 1:
            exist = True
            break
    
    if exist:
        for c in range(k, k+m):
            grid[r-1][c] = 1

        break
    
    if r == n-1 and exist==False:
        for c in range(k, k+m):
            grid[r][c] = 1

for i in range(n):
    for j in range(n):
        print(grid[i][j], end=" ")
    print()