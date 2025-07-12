n, k = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

d = dict()

for i in range(n):
    for j in range(i+1, n):
        if arr[i]+arr[j] in d:
            d[arr[i]+arr[j]] += 1
        else:
            d[arr[i]+arr[j]] = 1

print(d[k])