n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]
ans = 0

def inRange(x, y):
    return 0<=x<n and 0<=y<m

def calc1(x, y):

    result = 0
    for d in range(4):
        nx1, ny1 = x+dx[d], y+dy[d]
        nx2, ny2 = x+dx[(d+1)%4], y+dy[(d+1)%4]

        if inRange(nx1, ny1) and inRange(nx2, ny2):
            result = max(result, grid[x][y]+grid[nx1][ny1]+grid[nx2][ny2])
    
    return result

def calc2(x, y):
    result = 0
    for d in range(2):
        nx1, ny1 = x+dx[d], y+dy[d]
        nx2, ny2 = x+dx[(d+2)%4], y+dy[(d+2)%4]

        if inRange(nx1, ny1) and inRange(nx2, ny2):
            result = max(result, grid[x][y]+grid[nx1][ny1]+grid[nx2][ny2])
    
    return result

for i in range(n):
    for j in range(m):
        ans = max(ans, calc1(i, j))
        ans = max(ans, calc2(i, j))

print(ans)