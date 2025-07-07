n = int(input())

info = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

info.sort()

dp = [0]*n

for i in range(n):
    _, e, p1 = info[i]

    dp[i] = p1

    for j in range(i):
        s, _, p2 = info[j]

        if s <= e:
            continue
        
        dp[i] = max(dp[i], dp[j]+p1)

print(max(dp))