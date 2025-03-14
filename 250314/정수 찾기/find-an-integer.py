n = int(input())
a = list(map(int, input().split()))

sa = set(a)

m = int(input())
b = list(map(int, input().split()))

for num in b:
    if num in sa:
        print(1)
    else:
        print(0)