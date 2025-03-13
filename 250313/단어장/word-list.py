from sortedcontainers import SortedDict

n = int(input())

sd = SortedDict()

for _ in range(n):
    st = input()

    if st in sd:
        sd[st] += 1
    else:
        sd[st] = 1

for k, v in sd.items():
    print(k, v)