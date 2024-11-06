n = int(input())

arr = [
    int(input())
    for _ in range(n)
]

last_idx = n

def erase_num(s, e):
    global last_idx
    idx = 0

    for i in range(last_idx):
        if s <= i <= e:
            continue
        
        arr[idx] = arr[i]
        idx += 1
    
    last_idx = idx

for _ in range(2):
    s, e = tuple(map(int, input().split()))

    erase_num(s-1, e-1)

print(last_idx)
for i in range(last_idx):
    print(arr[i])