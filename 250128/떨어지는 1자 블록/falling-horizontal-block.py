n, m, k = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

def all_blank(r, s, e):
    return all([
        not grid[r][c] #모든 값이 0이면 True로 반환됨
        for c in range(s, e+1)
    ])

def get_row():
    for r in range(n-1):
        if not all_blank(r+1, k, k+m-1):
            return r
    
    return n-1

k -= 1

target = get_row()

for c in range(k, k+m):
    grid[target][c] = 1

for i in range(n):
    for j in range(n):
        print(grid[i][j], end=" ")
    print()
