n = int(input())

line = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

dp = [1] * n

line.sort()

for i in range(1, n):
    for j in range(i):
        x1, _ = line[i]
        _, x2 = line[j]

        if x2 < x1:
            dp[i] = max(dp[i], dp[j]+1)


print(max(dp))

