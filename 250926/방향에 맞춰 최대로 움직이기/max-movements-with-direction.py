n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dirs = [
    list(map(int, input().split()))
    for _ in range(n)
]

dxs, dys = [0, -1, -1, 0, 1, 1, 1, 0, -1], [0, 0, 1, 1, 1, 0, -1, -1, -1]

r, c = tuple(map(int, input().split()))
ans = 0


def can_go(x, y, cur_n):
    return 0<=x<n and 0<=y<n and grid[x][y] > cur_n

def find_max(x, y, cnt):
    global ans

    ans = max(ans, cnt)

    d = dirs[x][y]

    for i in range(n):
        nx, ny = x+dxs[d]*i, y+dys[d]*i

        if can_go(nx, ny, grid[x][y]):
            find_max(nx, ny, cnt+1)

find_max(r-1, c-1, 0)

print(ans)