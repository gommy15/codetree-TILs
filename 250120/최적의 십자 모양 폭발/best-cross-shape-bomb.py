n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

def simulation(x, y, num):
    cur_grid = grid

    for dx, dy in zip(dxs, dys):
        for i in range(num):
            nx, ny = x+dx*i, y+dy*i

            if 0<=nx<n and 0<=ny<n:
                cur_grid[nx][ny] = 0
    
    grav = [[0 for _ in range(n)] for _ in range(n)]

    for j in range(n):
        idx = n-1
        for i in range(n-1, -1, -1):
            if cur_grid[i][j]:
                grav[idx][j] = cur_grid[i][j]
                idx -= 1
    
    cnt = 0
    for i in range(n):
        for j in range(n-1):
            
            if grav[i][j] == 0:
                continue
            elif grav[i][j] == grav[i][j+1]:
                cnt += 1

            if grav[j][i] == 0:
                continue
            elif grav[j][i] == grav[j+1][i]:
                cnt += 1
                
    return cnt

ans = 0
for i in range(n):
    for j in range(n):
        ans = max(ans, simulation(i, j, grid[i][j]))

print(ans)