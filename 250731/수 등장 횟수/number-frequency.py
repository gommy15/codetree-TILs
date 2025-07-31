n, m = tuple(map(int, input().split()))

d = dict()

arr = list(map(int, input().split()))

for a in arr:
    d[a] = d.get(a, 0) + 1

tmp = list(map(int, input().split()))

for t in tmp:
    print(d.get(t, 0), end=" ")