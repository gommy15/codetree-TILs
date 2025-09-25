n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

spot = [
    (i, j)
    for i in range(n)
    for j in range(n)
    if grid[i][j] == 1
]

bomb = [
    [],
    [(-2, 0), (-1, 0), (0, 0), (1, 0), (2, 0)],
    [(-1, 0), (0, 1), (0, 0), (1, 0), (0, -1)],
    [(-1, -1), (-1, 1), (0, 0), (1, 1), (1, -1)]
]

ans = 0
visited = [[0]*n for _ in range(n)]

def possible(x, y):
    return 0<=x<n and 0<=y<n

def calc():
    for x, y in spot:
        bn = grid[x][y]

        for dx, dy in bomb[bn]:
            nx, ny = x+dx, y+dy

            if possible(nx, ny):
                visited[nx][ny] = 1
    
    return sum([
        visited[i][j]
        for i in range(n)
        for j in range(n)
    ])



def simulate(cnt):
    global ans, visited

    if cnt == len(spot):
        visited = [[0]*n for _ in range(n)]
        ans = max(ans, calc())
        return

    x, y = spot[cnt]
    for i in range(1, 4):
        grid[x][y] = i
        simulate(cnt+1)




simulate(0)

print(ans)