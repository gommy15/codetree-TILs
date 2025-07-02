n = int(input())

ans = 0
nums = []

def is_beauty():
    i = 0
    while i < n:
        if i + nums[i] -1 >= n:
            return False
        
        for j in range(i, i+nums[i]):
            if nums[j] != nums[i]:
                return False
        
        i += nums[i]
    
    return True

def find_num(cnt):
    if cnt == n:
        if is_beauty():
            global ans
            ans += 1
        return

    for i in range(1, 5):
        nums.append(i)
        find_num(cnt + 1)
        nums.pop()


find_num(0)

print(ans)