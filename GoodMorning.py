can_reach = {'0': {'0'},
             '1': {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'},
             '2': {'2', '3', '5', '6', '8', '9', '0'},
             '3': {'3', '6', '9'},
             '4': {'0', '4', '5', '6', '7', '8', '9'},
             '5': {'0', '5', '6', '8', '9'},
             '6': {'6', '9'},
             '7': {'7', '8', '9', '0'},
             '8': {'8', '9', '0'},
             '9': {'9'}
             }


def check_possible(num):
    str_num = str(num)
    possible = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
    for c in str_num:
        if c not in possible:
            return False
        possible = can_reach[c]
    return True


n_test_cases = int(input())
for _ in range(n_test_cases):
    num = int(input())
    diff = 0
    while True:
        if check_possible(num + diff):
            print(num + diff)
            break
        elif check_possible(num - diff):
            print(num - diff)
            break
        diff += 1
