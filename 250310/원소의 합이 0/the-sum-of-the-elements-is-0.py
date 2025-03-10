n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
d = list(map(int, input().split()))

count = dict()

ans = 0

for i in range(n):
    for j in range(n):
        sum_val = a[i] + b[j]

        if sum_val in count:
            count[sum_val] += 1
        else:
            count[sum_val] = 1

for i in range(n):
    for j in range(n):
        diff = -c[i]-d[j]

        if diff in count:
            ans += count[diff]

print(ans)