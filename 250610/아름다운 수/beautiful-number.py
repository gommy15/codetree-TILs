n = int(input())

num = []
ans = 0

def is_beutiful():
    i = 0

    while i<n:
        if i+num[i] -1 >= n:
            return False
        
        for j in range(i, i+num[i]):
            if num[j] != num[i]:
                return False
        
        i += num[i]
    
    return True

def get_num(cnt):
    global ans

    if cnt == n:
        if is_beutiful():
            ans += 1
        
        return
    
    for i in range(1, 5):
        num.append(i)
        get_num(cnt+1)
        num.pop()

get_num(0)

print(ans)