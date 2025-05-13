n = int(input())

arr = list(map(int, input().split()))

dp = [0] * n

for i in range(n):
    for j in range(0, i):
        if j != 0 and dp[j] == 0:
            continue
            
        if j+arr[j] >= i:
            dp[i] = max(dp[i], dp[j]+1)
    
print(max(dp))