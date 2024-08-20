n = int(input())

nums = [
    int(input())
    for _ in range(n)
]

max_cnt = 0
cnt = 1

for i in range(n):
    if(i==0 or nums[i-1] != nums[i]):
        max_cnt = max(max_cnt, cnt)
        cnt = 1
        continue
    
    cnt += 1


print(max_cnt)