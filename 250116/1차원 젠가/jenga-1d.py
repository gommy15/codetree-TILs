n = int(input())

arr = [
    int(input())
    for _ in range(n)
]

last_idx = n

for _ in range(2):
    s, e = tuple(map(int, input().split()))
    s -= 1
    e -= 1

    idx = 0
    tmp_arr = [0]*last_idx

    for i in range(last_idx):
        if s <= i <= e:
            continue
        
        tmp_arr[idx] = arr[i]
        idx += 1
    
    last_idx = idx
    for i in range(last_idx):
        arr[i] = tmp_arr[i]

print(last_idx)
for i in range(last_idx):
    print(arr[i])

