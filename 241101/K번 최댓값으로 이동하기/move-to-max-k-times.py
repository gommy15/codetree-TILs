import collections

NOT_EXISTS = (-1, -1)

n, k = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

r, c = tuple(map(int, input().split()))
curr_cell = (r-1, c-1)

bfs_q = collections.deque()
visited = [
    [0 for _ in range(n)]
    for _ in range(n)
]

def init_visited():
    for i in range(n):
        for j in range(n):
            visited[i][j] = 0

def inRange(x, y):
    return 0<=x<n and 0<=y<n

def canGo(x, y, tn):
    if not inRange(x, y):
        return False
    if grid[x][y] >= tn or visited[x][y]:
        return False
    
    return True

def bfs():
    dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

    curr_x, curr_y = curr_cell
    visited[curr_x][curr_y] = 1
    bfs_q.append(curr_cell)

    target_num = grid[curr_x][curr_y]

    while bfs_q:
        curr_x, curr_y = bfs_q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = curr_x+dx, curr_y+dy

            if canGo(nx, ny, target_num):
                bfs_q.append((nx, ny))
                visited[nx][ny] = 1

def need_update(best_pos, new_pos):
    if best_pos == NOT_EXISTS:
        return True
    
    best_x, best_y = best_pos
    new_x, new_y = new_pos

    return (grid[new_x][new_y], -new_x, -new_y) > (grid[best_x][best_y], -best_x, -best_y)

def move():
    global curr_cell

    init_visited()

    bfs()

    best_pos = NOT_EXISTS
    for i in range(n):
        for j in range(n):
            if not visited[i][j] or (i, j) == curr_cell:
                continue
            
            new_pos = (i, j)
            if need_update(best_pos, new_pos):
                best_pos = new_pos
    
    if best_pos == NOT_EXISTS:
        return False
    else:
        curr_cell = best_pos
        return True


for _ in range(k):
    is_moved = move()

    if not is_moved:
        break

final_x, final_y = curr_cell
print(final_x+1, final_y+1)