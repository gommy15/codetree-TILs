n = int(input())

info = [0] + list(map(int, input().split()))

dp = [0] *(n+1)

for i in range(1, n+1):
    dp[i] = info[i]
    for j in range(i):
        if i >= j:
            dp[i] = max(dp[i], dp[i-j]+info[j])

print(max(dp))