n = int(input())
lines = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

lines.sort()

dp = [1] * n

for i in range(n):

    x1, _ = lines[i]

    for j in range(i):
        _, x2 = lines[j]

        if x2 < x1:
            dp[i] = max(dp[i], dp[j]+1)

print(max(dp))