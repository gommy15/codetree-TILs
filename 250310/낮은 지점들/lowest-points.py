n = int(input())

spot = dict()

for _ in range(n):
    x, y = tuple(map(int, input().split()))

    if x in spot:
        spot[x] = min(spot[x], y)
    else:
        spot[x] = y

print(sum(list(spot.values())))