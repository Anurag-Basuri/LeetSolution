class Solution:
    def dfs(self, graph, vis, ans, node):
        if vis[node] == 2:
            return True

        if vis[node] == 1:
            return False

        vis[node] = 1

        for neighbor in graph[node]:
            if not self.dfs(graph, vis, ans, neighbor):
                return False

        vis[node] = 2
        ans.append(node)
        return True

    def eventualSafeNodes(self, graph):
        n = len(graph)
        vis = [0] * n
        ans = []

        for i in range(n):
            if vis[i] == 0:
                self.dfs(graph, vis, ans, i)

        ans.sort()
        return ans
