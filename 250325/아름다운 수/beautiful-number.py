n = int(input())

ans = 0
nums = []

def check():
    i=0

    while i<n:
        if i+nums[i]-1 >= n:
            return False
        
        for j in range(i, i+nums[i]):
            if nums[i] != nums[j]:
                return False
        
        i += nums[i]
    
    return True

def findbeauty(cnt):
    global ans

    if cnt == n:
        if check():
            ans += 1
        return
    
    for i in range(1, 5):
        nums.append(i)
        findbeauty(cnt + 1)
        nums.pop()


findbeauty(0)

print(ans)