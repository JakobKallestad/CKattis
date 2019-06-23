from math import sqrt


class UF:
    def __init__(self, n):
        self.id = [i for i in range(n)]
        self.size = [1 for _ in range(n)]

    def union(self, p, q):
        idp = self.find(p)
        idq = self.find(q)

        if self.size[idp] < self.size[idq]:
            self.id[idp] = idq
            self.size[idq] += self.size[idp]
        else:
            self.id[idq] = idp
            self.size[idp] += self.size[idq]

    def find(self, p):
        while p != self.id[p]:
            p = self.id[p]
            self.id[p] = self.id[self.id[p]]
        return p

    def connected(self, p, q):
        return self.find(p) == self.find(q)


n_test_cases = int(input())
for _ in range(n_test_cases):
    islands = []
    n_islands = int(input())
    for _ in range(n_islands):
        islands.append(tuple(map(float, input().split())))

    distances = []
    for i in range(len(islands)):
        for j in range(i+1, len(islands)):
            dist = sqrt((islands[i][0]-islands[j][0])**2 + (islands[i][1]-islands[j][1])**2)
            distances.append((i, j, dist))
    distances = sorted(distances, key=lambda x: x[2])
    uf = UF(n_islands)
    total_dist = 0
    for i1, i2, dist in distances:
        if not uf.connected(i1, i2):
            total_dist += dist
            uf.union(i1, i2)
    print(total_dist)
