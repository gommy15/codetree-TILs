from collections import deque

NOT_EXIST = (-1, -1)

n, k = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

r,c = tuple(map(int, input().split()))

q = deque()

visited = [[False]*n for _ in range(n)]
cur_pos = (r-1, c-1)

def can_go(x, y, k):
    return 0<=x<n and 0<=y<n and not visited[x][y] and grid[x][y] < k

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    x, y = cur_pos
    visited[x][y] = True
    q.append(cur_pos)
    t_num = grid[x][y]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny, t_num):
                visited[nx][ny] = True
                q.append((nx, ny))

def need_update(best_pos, new_pos):
    if best_pos == NOT_EXIST:
        return True
    
    bx, by = best_pos
    nx, ny = new_pos

    return (grid[nx][ny], -nx, -ny) > (grid[bx][by], -bx, -by)

def move():
    global cur_pos, visited

    visited = [[False]*n for _ in range(n)]

    bfs()

    best_pos = NOT_EXIST
    for i in range(n):
        for j in range(n):
            if not visited[i][j] or (i, j) == cur_pos:
                continue
            
            new_pos = (i, j)
            if need_update(best_pos, new_pos):
                best_pos = new_pos
    
    if best_pos == NOT_EXIST:
        return False
    else:
        cur_pos = best_pos
        return True


for _ in range(k):
    is_move = move()

    if not is_move:
        break
    
x, y = cur_pos
print(x+1, y+1)
