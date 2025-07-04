import sys
sys.setrecursionlimit(2500)

n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [[False]*n for _ in range(n)]

cnt_b = 0
block_max = 0
ans_bomb = 0

def can_go(x, y, k):
    return 0<=x<n and 0<=y<n and not visited[x][y] and grid[x][y] == k

def dfs(x, y, k):
    global cnt_b

    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    for dx, dy in zip(dxs, dys):
        nx, ny = x+dx, y+dy

        if can_go(nx, ny, k):
            visited[nx][ny] = True
            cnt_b += 1
            dfs(nx, ny, k)

for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            visited[i][j] = True
            cnt_b = 1
            dfs(i, j, grid[i][j])

            if cnt_b >= 4:
                ans_bomb += 1
            
            block_max = max(block_max, cnt_b)

print(ans_bomb, block_max)