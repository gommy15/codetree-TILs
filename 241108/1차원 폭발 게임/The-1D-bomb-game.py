n, m = tuple(map(int, input().split()))

arr = [int(input()) for _ in range(n)]

exist = True

def get_end_idx(s_idx, curr_num):
    for end_idx in range(s_idx+1, len(arr)):
        if arr[end_idx] != curr_num:
            return end_idx-1
    
    return len(arr) -1


while True:
    did_explode = False
    for curr_idx, num in enumerate(arr):
        if num == 0:
            continue
        
        end_idx = get_end_idx(curr_idx, num)

        if end_idx - curr_idx + 1 >= m:
            arr[curr_idx:end_idx+1] = [0] * (end_idx-curr_idx+1)
            did_explode = True
        
    arr = list(filter(lambda x:x>0, arr))

    if not did_explode:
        break

print(len(arr))
for num in arr:
    print(num)