a = input()

def run_encoding(target):
    encoded = ""

    cur_char = target[0]
    num_char = 1

    for target_c in target[1:]:
        if target_c == cur_char:
            num_char += 1
        else:
            encoded += cur_char
            encoded += str(num_char)

            cur_char = target_c
            num_char = 1
    
    encoded += cur_char
    encoded += str(num_char)

    return encoded


ans = len(run_encoding(a))
n = len(a)
num_shift = n-1

while num_shift:
    a = a[-1] + a[:-1]

    length = len(run_encoding(a))
    
    ans = min(ans, length)

    num_shift -= 1

print(ans)