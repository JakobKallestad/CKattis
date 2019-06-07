from math import log2

a, b = map(int, input().split())
if log2(a) <= b:
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")
