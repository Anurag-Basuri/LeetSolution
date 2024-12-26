class Solution:
    def eventualSafeNodes(self, graph):
        n = len(graph)
        ultagraph = [[] for _ in range(n)]
        indegree = [0] * n
        ans = []

        for i in range(n):
            for neighbor in graph[i]:
                ultagraph[neighbor].append(i)
                indegree[i] += 1

        q = deque()
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)

        while q:
            node = q.popleft()
            ans.append(node)

            for neighbor in ultagraph[node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)

        ans.sort()
        return ans
