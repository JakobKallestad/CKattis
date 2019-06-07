from math import factorial as fact

n_test_cases = int(input())
for _ in range(n_test_cases):
    target, n_sides, x, y, odds_multiplier = map(int, input().split())
    chance = (n_sides-target+1)/n_sides
    anti_chance = 1 - chance

    prob = 0
    for i in range(x, y+1):
        prob += fact(y)/(fact(i)*fact(y-i)) * chance**i * anti_chance**(y-i)
    if prob * odds_multiplier > 1:
        print("yes")
    else:
        print("no")
