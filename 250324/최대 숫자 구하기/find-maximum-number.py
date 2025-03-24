from sortedcontainers import SortedSet

n, m = tuple(map(int, input().split()))
arr = list(map(int, input().split()))

ss = SortedSet(range(1, m+1))

for num in arr:
    ss.remove(num)
    
    print(ss[-1])

    
    