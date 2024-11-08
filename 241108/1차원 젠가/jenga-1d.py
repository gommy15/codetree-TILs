n = int(input())

arr = [
    int(input())
    for _ in range(n)
]

last_idx = n

def without_b(s, e):
    global last_idx
    
    cnt = 0
    for i in range(last_idx):
        if s <= i <= e:
            continue

        arr[cnt] = arr[i]
        cnt += 1

    last_idx = cnt        
        
for _ in range(2):
    s, e = tuple(map(int, input().split()))

    without_b(s-1, e-1)

print(last_idx)
for i in range(last_idx):
    print(arr[i])