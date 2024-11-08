a = input()

def run_len_encoding(target):
    encoded = ""

    curr_char = target[0]
    num_char = 1
    for target_char in target[1:]:
        if target_char == curr_char:
            num_char += 1
        else:
            encoded += curr_char
            encoded += str(num_char)

            curr_char = target_char
            num_char = 1
        
    encoded += curr_char
    encoded += str(num_char)

    return encoded

min_len = len(run_len_encoding(a))
n = len(a)
num_shift = n-1


while num_shift:
    a = a[-1] + a[:-1]

    length = len(run_len_encoding(a))
    if min_len > length:
        min_len = length
    
    num_shift -= 1

print(min_len)