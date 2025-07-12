n = int(input())
arr = [0] + list(map(int, input().split()))

m = sum(arr)

dp = [[False]*(m+1) for _ in range(n+1)]

dp[0][0] = True

for i in range(1, n+1):
    for j in range(m+1):
        if j >= arr[i] and dp[i-1][j-arr[i]]:
            dp[i][j] = True
        
        if dp[i-1][j]:
            dp[i][j] = True

print("Yes" if dp[n][m//2] and m%2 == 0 else "No")