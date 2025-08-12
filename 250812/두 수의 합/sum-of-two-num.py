n, k = tuple(map(int, input().split()))

arr = list(map(int, input().split()))

d = dict()

ans = 0

for a in arr:
    tmp = k-a

    ans += d.get(tmp, 0)

    d[a] = d.get(a, 0) + 1

print(ans)
