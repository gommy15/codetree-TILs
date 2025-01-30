import sys
sys.setrecursionlimit(2500)

n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[False for _ in range(n)] for _ in range(n)]

bomb_cnt, max_bomb = 0, 0

dxs, dys = [-1, 1, 0, 0], [0, 0, -1, 1]

cnt = 0

def inRange(x, y):
    return 0<=x<n and 0<=y<n

def dfs(x, y):
    global cnt

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if inRange(nx, ny) and not visited[nx][ny] and grid[nx][ny] == grid[x][y]:
            cnt += 1
            visited[nx][ny] = True
            dfs(nx, ny)

for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            cnt = 0
            dfs(i, j)

            if cnt >= 4:
                bomb_cnt += 1
            max_bomb = max(max_bomb, cnt)

print(bomb_cnt, max_bomb)