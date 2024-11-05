n, t = tuple(map(int, input().split()))

arr = []

for _ in range(3):
    arr += list(map(int, input().split()))

while t:
    tmp = arr[3*n-1]

    for i in range(3*n-1, 0, -1):
        arr[i] = arr[i-1]
    
    arr[0] = tmp

    t -= 1

for i in range(3*n):
    if i != 0 and i%n == 0:
        print()
    print(arr[i], end = " ")