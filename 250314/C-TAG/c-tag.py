n, m = tuple(map(int, input().split()))

a = [input() for _ in range(n)]
b = [input() for _ in range(n)]

ans = 0
s = set()

def check(x, y, z):
    s.clear()

    for i in range(n):
        s.add(a[i][x]+a[i][y]+a[i][z])

    for i in range(n):
        if (b[i][x]+b[i][y]+b[i][z]) in s:
            return False
    
    return True

for i in range(m):
    for j in range(i+1, m):
        for k in range(j+1, m):

            if check(i, j, k):
                ans += 1

print(ans)