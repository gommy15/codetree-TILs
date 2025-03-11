from sortedcontainers import SortedDict

n = int(input())

sd = SortedDict()

nums = list(map(int, input().split()))

for i, st in enumerate(nums):
    if st not in sd:
        sd[st] = i+1

for k, v in sd.items():
    print(k, v)