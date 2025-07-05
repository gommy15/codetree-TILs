n = int(input())

arr = list(map(int, input().split()))

upper = [1]*n
lower = [1]*n

for i in range(1, n):
    for j in range(i):

        if arr[j] < arr[i]:
            upper[i] = max(upper[i], upper[j]+1)
        elif arr[j] > arr[i]:
            lower[i] = max(lower[i], lower[j]+1)
        
    
    lower[i] = max(lower[i], upper[i])

print(max(max(lower), max(upper)))