n = int(input())

arr = list(map(int, input().split()))

dp_upper = [1] * n
dp_lower = [1] * n

for i in range(1, n):
    for j in range(0, i):
        if arr[j] < arr[i]:
            dp_upper[i] = max(dp_upper[i], dp_upper[j]+1)
        
        if arr[j] > arr[i]:
            dp_lower[i] = max(dp_lower[i], dp_lower[j]+1)
    
    dp_lower[i] = max(dp_upper[i], dp_lower[i])

print(max(max(dp_upper), max(dp_lower)))