from collections import defaultdict
from itertools import combinations

n_known, n_want = map(int, input().split())
knows = list(map(int, input().split()))
wants = list(map(int, input().split()))

angles_map = defaultdict(set)
for i in range(1, 360):
    ang = i
    angles_map[i].add(ang)
    current_ang = (ang + ang) % 360
    while current_ang != ang:
        angles_map[i].add(current_ang)
        current_ang = (current_ang + ang) % 360

can_make = set()
for i in range(1, n_known+1):
    combs = combinations(knows, i)
    for co in combs:
        ang = sum(co)%360
        can_make = can_make.union(angles_map[ang])

# print(can_make)

for w in wants:
    if w in can_make:
        print("YES")
    else:
        print("NO")
