n, m = tuple(map(int, input().split()))

a = [0] + list(map(int, input().split()))

dp = [[False] * (m+1) for _ in range(n+1)]

dp[0][0] = True

for i in range(1, n+1):
    for j in range(m+1):
        if j >= a[i] and dp[i-1][j-a[i]]:
            dp[i][j] = True
        
        if dp[i-1][j]:
            dp[i][j] = True

if dp[n][m]:
    print("Yes")
else:
    print("No")