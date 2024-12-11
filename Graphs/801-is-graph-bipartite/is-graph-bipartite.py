class Solution:
    def dfs(self, graph, color, cur, n):
        color[cur] = n

        for neighbor in graph[cur]:
            if color[neighbor] == -1:
                if not self.dfs(graph, color, neighbor, 1 - n):
                    return False
            elif color[neighbor] == n:
                return False

        return True

    def isBipartite(self, graph):
        n = len(graph)
        color = [-1] * n

        for i in range(n):
            if color[i] == -1:
                if not self.dfs(graph, color, i, 1):
                    return False

        return True
