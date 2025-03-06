n, k = tuple(map(int, input().split()))

arr = list(map(int, input().split()))

d = dict()

for num in arr:
    if num in d:
        d[num] += 1
    else:
        d[num] = 1

tmp = [
    [v, k]
    for k, v in d.items()
]

tmp = sorted(tmp)

for i in range(len(tmp)-1, len(tmp)-k-1, -1):
    print(tmp[i][1], end = " ")
