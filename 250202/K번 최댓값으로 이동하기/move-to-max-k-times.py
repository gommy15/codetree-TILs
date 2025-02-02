from collections import deque

NOT_EXIST = (-1, -1)

n, k = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

r, c = tuple(map(int, input().split()))
cur_cell = (r-1, c-1)

q= deque()
visited = [[0 for _ in range(n)] for _ in range(n)]

def init_visited():
    for i in range(n):
        for j in range(n):
            visited[i][j] = 0

def can_go(x, y, num):
    return 0<=x<n and 0<=y<n and grid[x][y] < num and not visited[x][y]


def bfs():
    dxs, dys = [0, 1, 0, -1], [1, 0, -1, 0]

    cur_x, cur_y = cur_cell
    visited[cur_x][cur_y] = True
    q.append(cur_cell)

    target_n = grid[cur_x][cur_y]

    while q:
        cur_x, cur_y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = cur_x+dx, cur_y+dy

            if can_go(nx, ny, target_n):
                q.append((nx, ny))
                visited[nx][ny] = True

def need_update(best_pos, new_pos):
    if best_pos == NOT_EXIST:
        return True
    
    best_x, best_y = best_pos
    new_x, new_y = new_pos
    return (grid[new_x][new_y], -new_x, -new_y) > (grid[best_x][best_y], -best_x, -best_y)

def move():
    global cur_cell

    init_visited()

    bfs()

    best_pos = NOT_EXIST
    for i in range(n):
        for j in range(n):
            if not visited[i][j] or (i, j) == cur_cell:
                continue
            
            new_pos = (i, j)
            if need_update(best_pos, new_pos):
                best_pos = new_pos
    
    if best_pos == NOT_EXIST:
        return False
    else:
        cur_cell = best_pos
        return True

for _ in range(k):
    is_moved = move()

    if not is_moved:
        break


x, y = cur_cell
print(x+1, y+1)