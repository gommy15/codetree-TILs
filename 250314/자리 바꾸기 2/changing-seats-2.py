n, k = tuple(map(int, input().split()))

change = [
    tuple(map(int, input().split()))
    for _ in range(k)
]

s = [set() for _ in range(n+1)]
ans = [0 for _ in range(n+1)]

arr = [i for i in range(n+1)]

for i in range(1, n+1):
    s[i].add(i)
    ans[i] = 1

for _ in range(3):
    for (a, b) in change:
        arr[a], arr[b] = arr[b], arr[a]
    
        if a not in s[arr[a]]:
            s[arr[a]].add(a)
            ans[arr[a]] += 1
        
        if b not in s[arr[b]]:
            s[arr[b]].add(b)
            ans[arr[b]] += 1

for i in range(1, n+1):
    print(ans[i])