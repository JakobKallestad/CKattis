n_test_cases = int(input())
for _ in range(n_test_cases):
    n_people = int(input())
    people = []
    for _ in range(n_people):
        people.append(sum(list(map(int, input().split()))[1:]))
    #print(people)
    people.sort()
    average = 0
    elapsed_time = 0
    for p in people:
        elapsed_time += p
        average += elapsed_time
    print(average/n_people)
