from collections import deque

NOT_EXISTS = (-1, -1)

n, k = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

r, c = tuple(map(int, input().split()))
cur_pos = (r-1, c-1)

q = deque()
visited = [[False]*n for _ in range(n)]

def can_go(x, y, num):
    return 0<=x<n and 0<=y<n and grid[x][y] < num and not visited[x][y]

def bfs():
    dxs, dys = [0, 1, 0, -1], [1, 0, -1, 0]

    x, y = cur_pos
    visited[x][y] = True
    q.append(cur_pos)

    num_t = grid[x][y]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny, num_t):
                q.append((nx, ny))
                visited[nx][ny] = True

def need_update(best_pos, new_pos):
    if best_pos == NOT_EXISTS:
        return True
    
    bx, by = best_pos
    nx, ny = new_pos

    return (grid[nx][ny], -nx, -ny) > (grid[bx][by], -bx, -by)

def move():
    global cur_pos

    for i in range(n):
        for j in range(n):
            visited[i][j] = False

    bfs()

    best_pos = NOT_EXISTS

    for i in range(n):
        for j in range(n):
            if not visited[i][j] or (i, j) == cur_pos:
                continue
            
            new_pos = (i, j)
            if need_update(best_pos, new_pos):
                best_pos = new_pos
        
        if best_pos == NOT_EXISTS:
            return False
        else:
            cur_pos = best_pos
            return True

for _ in range(k):
    is_moved = move()

    if not is_moved:
        break

x, y = cur_pos

print(x+1, y+1)