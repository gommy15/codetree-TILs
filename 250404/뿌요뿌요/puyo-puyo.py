import sys
sys.setrecursionlimit(2500)

n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[False]*n for _ in range(n)]

bomb_cnt, bomb_size = 0, 0
cnt = 0

def can_go(x, y, num):
    return 0<=x<n and 0<=y<n and grid[x][y] == num and not visited[x][y]

def dfs(x, y, num):
    global cnt

    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny, num):
            visited[nx][ny] = True
            cnt += 1
            dfs(nx, ny, num)


for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            visited[i][j] = True
            cnt = 1
            dfs(i, j, grid[i][j])

            if cnt >= 4:
                bomb_cnt += 1
            
            bomb_size = max(bomb_size, cnt)

print(bomb_cnt, bomb_size)