n = int(input())

info = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

dp = [0]*n

for i in range(n):
    s, _, pi = info[i]

    dp[i] = pi

    for j in range(i):
        _, e, pj = info[j]

        if e < s:
            dp[i] = max(dp[i], dp[j]+pi)


print(max(dp))       