n = int(input())

arr = list(map(int, input().split()))

upper_dp = [0]*n
lower_dp = [0]*n

upper_dp[0] = lower_dp[0] = 1

for i in range(1, n):
    for j in range(i):

        # 증가 수열
        if arr[j] < arr[i]:
            upper_dp[i] = max(upper_dp[i], upper_dp[j]+1)
        
        # 감소 수열
        if arr[j] > arr[i]:
            lower_dp[i] = max(lower_dp[i], lower_dp[j]+1)


    # 증가 - 감소 수열
    lower_dp[i] = max(lower_dp[i], upper_dp[i])

print(max(max(upper_dp), max(lower_dp)))

