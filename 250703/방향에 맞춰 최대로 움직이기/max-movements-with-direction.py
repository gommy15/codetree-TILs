n = int(input())

num = [
    list(map(int, input().split()))
    for _ in range(n)
]
move_dir = [
    list(map(int, input().split()))
    for _ in range(n)
]
ans = 0


def can_go(x, y, p_num):
    return 0<=x<n and 0<=y<n and num[x][y] > p_num

def find_max(x, y, cnt):
    global ans
    
    ans = max(ans, cnt)

    dxs, dys = [-1, -1, 0, 1, 1, 1, 0, -1], [0, 1, 1, 1, 0, -1, -1, -1]

    d = move_dir[x][y] -1

    for i in range(n):
        nx, ny = x+dxs[d]*i, y+dys[d]*i

        if can_go(nx, ny, num[x][y]):
            find_max(nx, ny, cnt+1)

r, c = tuple(map(int, input().split()))
find_max(r-1, c-1, 0)
print(ans)