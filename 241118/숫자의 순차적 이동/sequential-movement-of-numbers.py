n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

num_spots = []

for i in range(n):
    for j in range(n):
        num_spots.append((grid[i][j], i, j))

num_spots.sort()

def simulate():
    dxs, dys = [-1, -1, -1, 0, 1, 1, 1, 0], [-1, 0, 1, 1, 1, 0, -1, -1]

    for i in range(n*n):
        max_num = 0
        tx, ty = 0, 0
        _, x, y = num_spots[i]

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if 0<=nx<n and 0<=ny<n and max_num < grid[nx][ny]:
                max_num = grid[nx][ny]
                tx, ty = nx, ny
        
        num_spots[i] = (i+1, tx, ty)
        num_spots[max_num-1] = (max_num, x, y)
        grid[tx][ty] = i+1
        grid[x][y] = max_num


for _ in range(m):
    simulate()

for i in range(n):
    for j in range(n):
        print(grid[i][j], end=" ")
    print()