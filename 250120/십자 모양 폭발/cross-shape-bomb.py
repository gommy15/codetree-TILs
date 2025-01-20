n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

r, c = tuple(map(int, input().split()))

r -= 1
c -= 1

dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

area = grid[r][c]

for dx, dy in zip(dxs, dys):
    for i in range(area):
        nx, ny = r+dx*i, c+dy*i

        if 0<=nx<n and 0<=ny<n:
            grid[nx][ny] = 0


ans = [[0]*n for _ in range(n)]

for i in range(n):
    idx = n-1
    for j in range(n-1, -1, -1):
        if grid[j][i] == 0:
            continue
        
        ans[idx][i] = grid[j][i]
        idx -= 1

for i in range(n):
    for j in range(n):
        print(ans[i][j], end=" ")
    print()