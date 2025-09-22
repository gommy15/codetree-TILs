DIR_NUM = 4

n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]

ans = 0

def in_range(x, y):
    return 0<=x<n and 0<=y<m

def sum1(x, y):
    result = 0

    for d in range(DIR_NUM):
        tmp = grid[x][y]

        nx1, ny1 = x+dx[d], y+dy[d]
        nx2, ny2 = x+dx[(d+1)%DIR_NUM], y+dy[(d+1)%DIR_NUM]

        if in_range(nx1, ny1) and in_range(nx2, ny2):
            result = max(result, tmp + grid[nx1][ny1] + grid[nx2][ny2])
    
    return result


def sum2(x, y):
    result = 0

    for d in range(2):
        tmp = grid[x][y]

        nx1, ny1 = x+dx[d], y+dy[d]
        nx2, ny2 = x+dx[(d+2)%DIR_NUM], y+dy[(d+2)%DIR_NUM]

        if in_range(nx1, ny1) and in_range(nx2, ny2):
            result = max(result, tmp + grid[nx1][ny1] + grid[nx2][ny2])
    
    return result


for i in range(n):
    for j in range(m):
        tmp = max(0, max(sum1(i, j), sum2(i, j)))

        ans = max(ans, tmp)

print(ans)

