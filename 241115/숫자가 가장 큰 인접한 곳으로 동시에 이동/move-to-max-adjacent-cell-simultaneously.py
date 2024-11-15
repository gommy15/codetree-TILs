n, m, t = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

#ball = [[0]*n for _ in range(n)]

ball_spot = []

for _ in range(m):
    r, c = tuple(map(int, input().split()))
    ball_spot.append((r-1, c-1))

def move():
    dxs, dys = [-1, 1, 0, 0], [0, 0, -1, 1]
    new_ball = [[0]*n for _ in range(n)]

    for x, y in ball_spot:
        max_num = grid[x][y]
        max_pos = (x, y)

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if 0<=nx<n and 0<=ny<n and max_num < grid[nx][ny]:
                max_pos = (nx, ny)
                max_num = grid[nx][ny]
        
        if max_num != grid[x][y]:
            nx, ny = max_pos
            new_ball[nx][ny] += 1

    ball_spot.clear()

    for i in range(n):
        for j in range(n):
            if new_ball[i][j] == 1:
                ball_spot.append((i, j))


for _ in range(t):
    move()

ans = len(ball_spot)

print(ans)