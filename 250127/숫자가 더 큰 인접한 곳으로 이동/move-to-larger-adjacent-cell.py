n, r, c = tuple(map(int, input().split()))
r -= 1
c -= 1

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dxs, dys = [-1, 1, 0, 0], [0, 0, -1, 1]
visited_num = []

def inRange(x, y):
    return 0<=x<n and 0<=y<n

def simulation():
    global r, c
    
    for dx, dy in zip(dxs, dys):
        nx, ny = r+dx, c+dy

        if inRange(nx, ny) and grid[r][c] < grid[nx][ny]:
            r, c = nx, ny
            return True

    return False

visited_num.append(grid[r][c])
while True:
    if not simulation():
        break
    
    visited_num.append(grid[r][c])

for num in visited_num:
    print(num, end=" ")
