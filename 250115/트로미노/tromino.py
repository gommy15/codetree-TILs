n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

def inRange(x, y):
    return 0<=x<n and 0<=y<m

dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

def sum1(x, y):
    max_sum = 0
    for d in range(4):
        nx1, ny1 = x+dxs[d], y+dys[d]
        nx2, ny2 = x+dxs[(d+1)%4], y+dys[(d+1)%4]

        if inRange(nx1, ny1) and inRange(nx2, ny2):
            max_sum = max(max_sum, grid[x][y]+grid[nx1][ny1]+grid[nx2][ny2])
    
    return max_sum

def sum2(x, y):
    max_sum = 0
    for d in range(2):
        cur_sum = 0
        nx1, ny1 = x+dxs[d], y+dys[d]
        nx2, ny2 = x+dxs[d+2], y+dys[d+2]

        if inRange(nx1, ny1) and inRange(nx2, ny2):
            max_sum = max(max_sum, grid[x][y]+grid[nx1][ny1]+grid[nx2][ny2])
        
        max_sum = max(max_sum, cur_sum)
    
    return max_sum


ans = 0

for i in range(n):
    for j in range(m):
        ans = max(ans, sum1(i, j))
        ans = max(ans, sum2(i, j))

print(ans)