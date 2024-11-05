n, m, q = tuple(map(int, input().split()))
a = [
    list(map(int, input().split()))
    for _ in range(n)
]
tmp_arr = [[0 for _ in range(m)] for _ in range(n)]

def rotate(sr, sc, er, ec):
    tmp = a[sr][sc]

    for r in range(sr, er):
        a[r][sc] = a[r+1][sc]
    
    for c in range(sc, ec):
        a[er][c] = a[er][c+1]

    for r in range(er, sr, -1):
        a[r][ec] = a[r-1][ec]

    for c in range(ec, sc, -1):
        a[sr][c] = a[sr][c-1]
    
    a[sr][sc+1] = tmp

def inRange(x, y):
    return 0<=x<n and 0<=y<m

def average(x, y):
    dxs, dys = [0, -1, 0, 1, 0], [0, 0, 1, 0, -1]

    ac_number = [
        a[x+dx][y+dy]
        for dx, dy in zip(dxs, dys)
        if inRange(x+dx, y+dy)
    ]

    return sum(ac_number) // len(ac_number)

def set_average(sr, sc, er, ec):
    for i in range(sr, er+1):
        for j in range(sc, ec+1):
            tmp_arr[i][j] = average(i, j)
    
    for i in range(sr, er+1):
        for j in range(sc, ec+1):
            a[i][j] = tmp_arr[i][j]

def simulate(sr, sc, er, ec):
    rotate(sr, sc, er, ec)

    set_average(sr, sc, er, ec)

for _ in range(q):
    r1, c1, r2, c2 = tuple(map(int, input().split()))

    simulate(r1-1, c1-1, r2-1, c2-1)

for i in range(n):
    for j in range(m):
        print(a[i][j], end=" ")
    print()