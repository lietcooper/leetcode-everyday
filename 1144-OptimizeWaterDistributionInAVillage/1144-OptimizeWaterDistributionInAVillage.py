# Last updated: 12/8/2025, 11:26:24 PM
class UnionFind:
    def __init__(self, size):
        self.root = [i for i in range(size + 1)]
        self.rank = [0] * (size + 1)

    def find(self, u):
        if u != self.root[u]:
            self.root[u] = self.find(self.root[u])
        return self.root[u]

    def join(self, u, v):
        u = self.find(u)
        v = self.find(v)

        if u == v:
            return False
        else:
            if self.rank[u] > self.rank[v]:
                self.root[v] = u
            elif self.rank[u] < self.rank[v]:
                self.root[u] = v
            else:
                self.root[u] = v
                self.rank[v] += 1
            return True

class Solution:    
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
        edges = [i for i in pipes]
        for index, cost in enumerate(wells):
            edges.append((0, index + 1, cost))

        edges.sort(key = lambda x : x[2])

        uf = UnionFind(n)
        cost = 0
        for start, end, weight in edges:
            if uf.join(start, end):
                cost += weight
        
        return cost
        
        