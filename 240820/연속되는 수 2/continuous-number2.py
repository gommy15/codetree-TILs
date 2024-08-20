n = int(input())

nums = [
    int(input())
    for _ in range(n)
]

max_cnt, cnt = 0, 0

for i in range(n):
    if(i==0 or nums[i-1] != nums[i]):
        cnt = 1
    else:
        cnt += 1

    max_cnt = max(max_cnt, cnt)


print(max_cnt)