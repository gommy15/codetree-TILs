from sortedcontainers import SortedSet

n, m = tuple(map(int, input().split()))

arr = list(map(int, input().split()))

ss = SortedSet()

for num in arr:
    ss.add(num)

for _ in range(m):
    x = int(input())

    idx = ss.bisect_left(x)

    if idx == len(ss):
        print(-1)
    else:
        print(ss[idx])