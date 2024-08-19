m1, d1, m2, d2 = tuple(map(int, input().split()))

days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

sum1 = 0
for i in range(1, m1):
    sum1 += days[i];
sum1 += d1

sum2 = 0
for i in range(1, m2):
    sum2 += days[i]
sum2 += d2

print(sum2 - sum1+1)