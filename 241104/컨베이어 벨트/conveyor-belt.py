n, t = tuple(map(int, input().split()))

arr = list(map(int, input().split()))+list(map(int, input().split()))

while(t != 0):
    tmp = arr[-1]

    for i in range(2*n-1, 0, -1):
        arr[i] = arr[i-1]
    
    arr[0] = tmp
    t -= 1

for i in range(2*n):
    if i%n == 0 and i != 0:
        print()
    print(arr[i], end=" ")