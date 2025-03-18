from sortedcontainers import SortedSet

n, m = tuple(map(int, input().split()))

ss = SortedSet()

for _ in range(n):
    x, y = tuple(map(int, input().split()))

    ss.add((x, y))


for _ in range(m):
    x, y = tuple(map(int, input().split()))

    idx = ss.bisect_left((x, y))

    if idx == len(ss):
        print(-1, -1)
    else:
        print(ss[idx][0], ss[idx][1])
    