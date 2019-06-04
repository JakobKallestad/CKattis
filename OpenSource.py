from collections import defaultdict

unis = defaultdict(set)
currentUni = ""
has_voted = set()
voted_twice = set()

while True:
    inp = input()
    if inp[0].isupper():
        currentUni = inp
        unis[currentUni].add(currentUni)

    elif inp[0].islower():
        if inp in unis[currentUni]:
            continue
        if inp in has_voted:
            voted_twice.add(inp)
            continue
        unis[currentUni].add(inp)
        has_voted.add(inp)

    elif inp[0] == '1':
        for k, v in unis.items():
            v = len(v - voted_twice)-1
            unis[k] = v

        unis_sorted = sorted(unis.items(), key=lambda x:x[0])
        unis_sorted = sorted(unis_sorted, key=lambda x:x[1], reverse=True)
        for k, v in unis_sorted:
            print(k, v)
        unis = defaultdict(set)
        currentUni = ""
        has_voted = set()
        voted_twice = set()

    else:
        break
