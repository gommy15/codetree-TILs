n = int(input())

info = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

dp = [0]*n

info.sort()

for i in range(n):
    dp[i] = info[i][2]

for i in range(1, n):
    for j in range(0, i):
        s, _, p = info[i]
        _, e, _ = info[j]

        if s < e:
            dp[i] = max(dp[i], dp[j]+p)

print(max(dp))