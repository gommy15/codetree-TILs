n, k = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

d = dict()

for a in arr:
    d[a] = d.get(a, 0) + 1

ans = 0

for i in range(n):
    d[arr[i]] -= 1

    for j in range(i):
        diff = k - d[arr[i]] - d[arr[j]]

        ans += d.get(diff, 0)

print(ans)