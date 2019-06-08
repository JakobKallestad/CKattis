from fractions import Fraction

n_test_cases = int(input())
for _ in range(n_test_cases):
    nums = list(map(str, input().split()))
    x1, y1, x2, y2 = int(nums[0]), int(nums[1]), int(nums[3]), int(nums[4])
    op = nums[2]
    f1 = Fraction(x1, y1)
    f2 = Fraction(x2, y2)
    if op == '+':
        res = str(f1+f2)
    elif op == '-':
        res = str(f1-f2)
    elif op == '*':
        res = str(f1*f2)
    else:
        res = str(f1/f2)

    if '/' not in res:
        print(res+" / 1")
    else:
        res = res.replace("/", " / ")
        print(res)
