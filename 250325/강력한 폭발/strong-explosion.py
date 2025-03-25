n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

bomb_pos = [
    (x, y)
    for x in range(n)
    for y in range(n)
    if grid[x][y]
]

bomb_type = [
    [],
    [(-2, 0), (-1, 0), (0, 0), (1, 0), (2, 0)],
    [(-1, 0), (0, 1), (0, 0), (1, 0), (0, -1)],
    [(-1, -1), (-1, 1), (0, 0), (1, 1), (1, -1)]
]

bombed = [[False for _ in range(n)] for _ in range(n)]
ans = 0

def canGo(x, y):
    return 0<=x<n and 0<=y<n and not bombed[x][y]

def Calc():
    for i in range(n):
        for j in range(n):
            bombed[i][j] = False
    
    for x, y in bomb_pos:
        for dx, dy in bomb_type[grid[x][y]]:
            nx, ny = x+dx, y+dy

            if canGo(nx, ny):
                bombed[nx][ny] = True
    
    return sum([
        bombed[i][j]
        for i in range(n)
        for j in range(n)
    ])

def findMaxArea(idx):
    if idx == len(bomb_pos):
        global ans

        ans = max(ans, Calc())
        return
    
    x, y = bomb_pos[idx]

    for i in range(1, 4):
        grid[x][y] = i
        findMaxArea(idx+1)


findMaxArea(0)

print(ans)