n, m = tuple(map(int, input().split()))

d = dict()

arr = list(map(int, input().split()))

for num in arr:
    if num not in d:
        d[num] = 1
    else:
        d[num] += 1

qes = list(map(int, input().split()))

for num in qes:
    if num in d:
        print(d[num], end=" ")
    else:
        print(0, end=" ")