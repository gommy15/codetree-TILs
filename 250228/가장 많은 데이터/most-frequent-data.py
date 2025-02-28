n = int(input())
d = dict()

ans = 0

for _ in range(n):
    st = input()

    if st not in d:
        d[st] = 1
    else:
        d[st] += 1
    
    #ans = max(ans, d[st])

for k in d:
    ans = max(ans, d[k])

print(ans)