n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

max_gold = 0

def get_area(k):
    return k*k + (k+1)*(k+1)

def get_gold_cnt(x, y, k):
    return sum([
        grid[i][j]
        for i in range(n)
        for j in range(n)
        if abs(x-i)+abs(y-j) <= k
    ])

for i in range(n):
    for j in range(n):
        for k in range(2*(n-1)+1):
            gold_cnt = get_gold_cnt(i, j, k)

            if gold_cnt * m >= get_area(k):
                max_gold = max(max_gold, gold_cnt)

print(max_gold)