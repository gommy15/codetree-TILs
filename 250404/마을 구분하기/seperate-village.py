n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[False]*n for _ in range(n)]

village = []
nums = 0

def can_go(x, y):
    return 0<=x<n and 0<=y<n and grid[x][y] and not visited[x][y]

def dfs(x, y):
    global nums

    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny):
            visited[nx][ny] = True
            nums += 1
            dfs(nx, ny)

for i in range(n):
    for j in range(n):
        if grid[i][j] and not visited[i][j]:
            visited[i][j] = True
            nums = 1
            dfs(i, j)

            village.append(nums)

village.sort()

print(len(village))
for num in village:
    print(num)