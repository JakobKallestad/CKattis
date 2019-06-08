from collections import deque

# INPUT
n = int(input())
line = input()
grid = []
target = "ICPCASIASG"
for i in range(n):
    grid.append(line[i*n:(i+1)*n])


def pre_compute_moves():
    all_moves = {}
    for y in range(n):
        for x in range(n):
            moves = move((y, x))
            all_moves[(y, x)] = moves
    return all_moves


def move(loc):
    y, x = loc
    moves = []
    if 0 <= y-2 and x+1 < n:
        moves.append((y-2, x+1))  # north-east X
    if 0 <= y-1 < n and x+2 < n:
        moves.append((y-1, x+2))  # east-north X
    if y+1 < n and x+2 < n:
        moves.append((y+1, x+2))  # east-south X
    if y+2 < n and x+1 < n:
        moves.append((y+2, x+1))  # south-east X
    if y+2 < n and 0 <= x-1:
        moves.append((y+2, x-1))  # south-west X
    if y+1 < n and 0 <= x-2:
        moves.append((y+1, x-2))  # west-south X
    if 0 <= y-1 < n and 0 <= x-2:
        moves.append((y-1, x-2))  # west-north X
    if 0 <= y-2 and 0 <= x-1:
        moves.append((y-2, x-1))  # north-west X
    return moves


def search(start_y, start_x, move_dict):
    global success
    if grid[start_y][start_x] != target[0]:
        return
    ci = 0
    queue = deque()
    queue.append(((start_y, start_x), ci))

    while queue:
        loc, ci = queue.popleft()
        moves = move_dict[loc]
        for y, x in moves:
            if grid[y][x] == target[ci+1]:
                if ci+1 == 9:
                    success = True
                    return True
                queue.append(((y, x), ci+1))
    return False


def search_all(move_dict):
    for y in range(n):
        for x in range(n):
            if search(y, x, move_dict):
                print("YES")
                return
    print("NO")


def main():
    move_dict = pre_compute_moves()
    search_all(move_dict)


main()
