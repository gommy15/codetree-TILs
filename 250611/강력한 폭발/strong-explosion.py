n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

bombed = [
    [False for _ in range(n)]
    for _ in range(n)
]

bomb_type = [
    [],
    [[-2, 0], [-1, 0], [0, 0], [1, 0], [2, 0]],
    [[-1, 0], [1, 0], [0, 0], [0, -1], [0, 1]],
    [[-1, -1], [-1, 1], [0, 0], [1, -1], [1, 1]]
]

bomb_pos = []

ans = 0

def inrange(x, y):
    return 0<=x<n and 0<=y<n

def bomb(x, y, bt):
    for i in range(5):
        dx, dy = bomb_type[bt][i]
        nx, ny = x+dx, y+dy

        if inrange(nx, ny):
            bombed[nx][ny] = True

def calc():
    for i in range(n):
        for j in range(n):
            bombed[i][j] = False
    
    for i in range(n):
        for j in range(n):
            if grid[i][j]:
                bomb(i, j, grid[i][j])
    
    return sum(
        bombed[i][j]
        for i in range(n)
        for j in range(n)
    )

def find_max_area(cnt):
    global ans

    if cnt == len(bomb_pos):
        ans = max(ans, calc())
        return

    for i in range(1, 4):
        x, y = bomb_pos[cnt]

        grid[x][y] = i
        find_max_area(cnt+1)
        grid[x][y] = 0

for i in range(n):
    for j in range(n):
        if grid[i][j] == 1:
            bomb_pos.append((i, j))


find_max_area(0)

print(ans)


