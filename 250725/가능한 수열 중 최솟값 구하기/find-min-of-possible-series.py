import sys

n = int(input())
numbers = [4, 5, 6]

seq = []

def is_possible():
    leng = 1

    while True:
        s1, e1 = len(seq)-leng, len(seq)-1
        s2, e2 = s1-leng, s1-1

        if s2 < 0:
            break
        
        if seq[s1:e1+1] == seq[s2:e2+1]:
            return False

        leng += 1
    
    return True

def find_min_seq(cnt):
    if cnt == n:
        for s in seq:
            print(s, end="")
        sys.exit(0)
    
    for num in numbers:
        seq.append(num)
        
        if is_possible():
            find_min_seq(cnt+1)
        
        seq.pop()


find_min_seq(0)
