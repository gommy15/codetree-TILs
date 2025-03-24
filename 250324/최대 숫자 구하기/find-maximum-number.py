from sortedcontainers import SortedSet

n, m = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

ss = SortedSet()

for i in range(1, m+1):
    ss.add(i)

for num in arr:
    if num in ss:
        ss.remove(num)
    
    print(ss[-1])

    
    