n, k = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

d = dict()

ans = 0

for elem in arr:
    diff = k-elem

    if diff in d:
        ans += d[diff]

    if elem in d:
        d[elem] += 1
    else:
        d[elem] = 1

print(ans)