MAX_MOV = 1000000

a_mov, b_mov = [0] * (MAX_MOV+1), [0] * (MAX_MOV+1)

n, m = tuple(map(int, input().split()))

idx_a = 1
for _ in range(n):
    d, t = tuple(input().split())
    for _ in range(int(t)):
        a_mov[idx_a] = a_mov[idx_a-1] + (1 if d == 'R' else -1)
        idx_a += 1


idx_b = 1
for _ in range(m):
    d, t = tuple(input().split())
    for _ in range(int(t)):
        b_mov[idx_b] = b_mov[idx_b-1] + (1 if d == 'R' else -1)
        idx_b += 1

ans = -1

for i in range(1, idx_a):
    if a_mov[i] == b_mov[i]:
        ans = i
        break

print(ans)