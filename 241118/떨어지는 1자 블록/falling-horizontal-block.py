n, m, k = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

k -= 1

for r in range(n-1, -1, -1):
    exist = False
    for c in range(k, k+m):
        if grid[r][c] == 1:
            exist = True
            break
    
    if exist == False:
        for c in range(k, k+m):
            grid[r][c] = 1

        break

for i in range(n):
    for j in range(n):
        print(grid[i][j], end=" ")
    print()