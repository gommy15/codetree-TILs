import collections

NOT_EXISTS = (-1, -1)

n, k = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

r, c = tuple(map(int, input().split()))
cur_cell = (r-1, c-1)

q = collections.deque()
visited = [[False]*n for _ in range(n)]

def can_go(x, y, t):
    return 0<=x<n and 0<=y<n and not visited[x][y] and grid[x][y] < t

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    x, y = cur_cell
    visited[x][y] = True
    q.append((x, y))

    num = grid[x][y]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny, num):
                q.append((nx, ny))
                visited[nx][ny] = True

def need_update(best_pos, new_pos):
    if best_pos == NOT_EXISTS:
        return True
    
    x, y = best_pos
    nx, ny = new_pos

    return (grid[nx][ny], -nx, -ny) > (grid[x][y], -x, -y)

def move():
    global cur_cell, visited

    visited = [[False]*n for _ in range(n)]

    bfs()

    best_pos = NOT_EXISTS

    for i in range(n):
        for j in range(n):
            if not visited[i][j] or (i, j) == cur_cell:
                continue
            
            new_pos = (i, j)
            if need_update(best_pos, new_pos):
                best_pos = new_pos
    
    if best_pos == NOT_EXISTS:
        return False
    else:
        cur_cell = best_pos
        return True

for _ in range(k):
    is_moved = move()

    if not is_moved:
        break
    
print(cur_cell[0]+1, cur_cell[1]+1)