len_to_num = {}

first = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"]
second = ["eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
third = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
fourth = ["onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred",
          "eighthundred", "ninehundred"]

for i in range(999, 0, -1):
    if i <= 10:
        len_to_num[i-len(first[i - 1])] = first[i - 1]
    elif i <= 19:
        len_to_num[i-len(second[i - 11])] = second[i - 11]
    elif i <= 99:
        if i % 10 == 0:
            len_to_num[i-len(third[i//10-2])] = third[i//10-2]
        else:
            a = i/10
            b = i%10
            res = third[i//10-2]+first[b-1]
            len_to_num[i-len(res)] = res
    else:
        if i % 100 == 0:
            len_to_num[i-len(fourth[i//100-1])] = fourth[i//100-1]
        else:
            a = fourth[i//100-1]
            rem = i % 100
            if rem % 10 == 0:
                len_to_num[i-len(a+third[rem//10-2])] = a+third[rem//10-2]
            elif rem <= 10:
                res = a+first[rem-1]
                len_to_num[i-len(res)] = res
            elif rem <= 19:
                res = a+second[rem-11]
                len_to_num[i-len(res)] = res
            else:
                b = third[rem//10-2]
                c = rem % 10
                res = a+b+first[c-1]
                temp = i-len(res)
                len_to_num[i-len(res)] = res

n_lines = int(input())
char_count = 0
output = []
target_ind = 0
for i in range(n_lines):
    line = input()
    if line == "$":
        target_ind = i
    else:
        char_count += len(line)
    output.append(line)

target = len_to_num[char_count]
output[target_ind] = target
print(' '.join(output))
