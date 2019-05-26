
low, high, lying = 0, 11, False
lies = []


while True:
    num = int(input())
    if num == 0:
        break
    line = input()
    if line == "too high":
        if num <= low:
            lying = True
        if high == 11:
            high = num
        else:
            high = min(high, num)
    elif line == "too low":
        if num >= high:
            lying = True
        if low == 0:
            low = num
        else:
            low = max(low, num)
    else:
        if low >= num or num >= high:
            lying = True
        lies.append(lying)
        low, high, lying = 0, 11, False

for l in lies:
    if l:
        print("Stan is dishonest")
    else:
        print("Stan may be honest")



