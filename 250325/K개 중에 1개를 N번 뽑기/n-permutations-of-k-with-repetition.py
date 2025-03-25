k, n = tuple(map(int, input().split()))

seq = []

def printSeq():
    for num in seq:
        print(num, end=" ")
    print()

def getSeq(cnt):
    if cnt == n:
        printSeq()
        return
    
    for i in range(1, k+1):
        seq.append(i)
        getSeq(cnt+1)
        seq.pop()

getSeq(0)
