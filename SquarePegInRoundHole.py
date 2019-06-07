from math import sqrt

n_plots, n_circles, n_squares = map(int, input().split())
plots = list(map(int, input().split()))
circles = list(map(int, input().split()))
squares = list(map(int, input().split()))

for sq in squares:
    radius = (sq * sqrt(2))/2
    circles.append(radius)

plots.sort(reverse=True)
circles.sort(reverse=True)
i, j = 0, 0
count = 0
while j < len(plots) and i < len(circles):
    if circles[i] < plots[j]:
        count += 1
        i += 1
        j += 1
    else:
        i += 1

print(count)
