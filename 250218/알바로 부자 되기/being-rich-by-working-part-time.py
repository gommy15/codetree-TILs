n = int(input())

info = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

info.sort()

dp = [0] * n

for i in range(n):
    s, _, p1 = info[i]
    dp[i] = p1

    for j in range(i):
        _, e, p2 = info[j]

        if e < s:
            dp[i] = max(dp[i], dp[j] + p1)

print(max(dp))
