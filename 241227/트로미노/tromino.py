n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]

def InRange(x, y):
    return 0<=x<n and 0<=y<n

def Sum1(x, y):
    summ = 0
    for d in range(4):
        nx1, ny1 = x+dx[d], y+dy[d]
        nx2, ny2 = x+dx[(d+1)%4], y+dy[(d+1)%4]

        if(InRange(nx1, ny1) and InRange(nx2, ny2)):
            summ = max(summ, grid[x][y] + grid[nx1][ny1] + grid[nx2][ny2])
    
    return summ

def Sum2(x, y):
    summ = 0
    for d in range(2):
        nx1, ny1 = x+dx[d], y+dy[d]
        nx2, ny2 = x+dx[d+2], y+dy[d+2]

        if(InRange(nx1, ny1) and InRange(nx2, ny2)):
            summ = max(summ, grid[x][y] + grid[nx1][ny1] + grid[nx2][ny2])
    
    return summ

ans = 0

for i in range(n):
    for j in range(m):
        ans = max(ans, Sum1(i, j))
        ans = max(ans, Sum2(i, j))

print(ans)