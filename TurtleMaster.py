grid = []
for _ in range(8):
    grid.append(list(input()))

code = list(input())
direction = 0
tx, ty = 0, 7
all_directions = ['E', 'S', 'W', 'N']  # 0, 1, 2, 3
deltas = {0: (1, 0), 1: (0, 1), 2: (-1, 0), 3: (0, -1)}
dx, dy = 1, 0

for c in code:
    if c == 'F':
        if not (0 <= tx + dx <= 7 and 0 <= ty + dy <= 7):
            print("Bug!")
            break
        elif grid[ty + dy][tx + dx] == 'I' or grid[ty + dy][tx + dx] == 'C':
            print("Bug!")
            break
        else:
            tx += dx
            ty += dy
    elif c == 'R':
        direction = (direction + 1) % 4
        dx, dy = deltas[direction]
    elif c == 'L':
        if direction == 0:
            direction = 3
        else:
            direction -= 1
        dx, dy = deltas[direction]
    elif c == 'X':
        if not (0 <= tx + dx <= 7 and 0 <= ty + dy <= 7):
            print("Bug!")
            break
        elif grid[ty + dy][tx + dx] == 'I':
            grid[ty + dy][tx + dx] = '.'
        else:
            print("Bug!")
            break
else:
    if grid[ty][tx] == 'D':
        print("Diamond!")
    else:
        print("Bug!")
