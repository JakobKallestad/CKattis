import sys

n_students, target = map(int, input().split())
students = list(map(int, input().split()))
their_score = sum(students)
average = their_score/n_students

if average == 0 and their_score > 0:
    print("impossible")
    sys.exit()

if average == target:
    print(0)
    sys.exit()

for i in range(n_students+1, 5000):
    missing_score = target*i - their_score
    if 0 <= missing_score/(i - n_students) <= 100:
        print(i-n_students)
        break
else:
    print("impossible")
