n_test_cases = int(input())
for _ in range(n_test_cases):
    n_rotates, line = map(str, input().split())
    n_rotates = int(n_rotates)
    start_ind = 0
    end_ind = len(line)
    cur_size = len(line)
    for i in range(min(24, n_rotates)):
        remove = cur_size // 4
        if i % 2 == 0:
            start_ind += remove
        else:
            end_ind -= remove
        cur_size -= remove
    print(line[start_ind:end_ind])
