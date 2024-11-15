n, m, t = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

ball = [[0]*n for _ in range(n)]

ball_spot = []

for _ in range(m):
    r, c = tuple(map(int, input().split()))
    ball_spot.append((r-1, c-1))
    ball[r-1][c-1] = 1

def move():
    dxs, dys = [-1, 1, 0, 0], [0, 0, -1, 1]

    for x, y in ball_spot:
        max_num = grid[x][y]
        max_pos = (x, y)

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if 0<=nx<n and 0<=ny<n and max_num < grid[nx][ny]:
                max_pos = (nx, ny)
                max_num = grid[nx][ny]
        
        ball[x][y] -= 1
        nx, ny = max_pos
        ball[nx][ny] += 1

    ball_spot.clear()
    
    for i in range(n):
        for j in range(n):
            if ball[i][j] == 0:
                continue
            elif ball[i][j] == 1:
                ball_spot.append((i, j))
            else:
                ball[i][j] = 0


for _ in range(t):
    move()

ans = sum(sum(r) for r in ball)

print(ans)