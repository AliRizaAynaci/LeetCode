class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        
        edges = set()
        
        for i, j in connections:
            edges.add((i, j))
            
        neighbours = {}
        
        for city in range(n):
            neighbours[city] = []
        
        for a, b in connections:
            neighbours[a].append(b)
            neighbours[b].append(a)
            
        visit = set()
        
        counter = 0

        def dfs(city):
            nonlocal edges, neighbours, counter, visit
            for neighbour in neighbours[city]:
                if neighbour in visit:
                    continue
                if (neighbour, city) not in edges:
                    counter += 1
                visit.add(neighbour)
                dfs(neighbour)
        visit.add(0)
        dfs(0)
        return counter