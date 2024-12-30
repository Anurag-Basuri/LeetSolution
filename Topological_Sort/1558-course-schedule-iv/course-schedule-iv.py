from collections import deque

class Solution:
    def checkIfPrerequisite(self, numCourses, prerequisites, queries):
        graph = [[] for _ in range(numCourses)]
        reachable = [[0] * numCourses for _ in range(numCourses)]
        indegree = [0] * numCourses

        for pre in prerequisites:
            graph[pre[0]].append(pre[1])
            indegree[pre[1]] += 1

        q = deque([i for i in range(numCourses) if indegree[i] == 0])

        while q:
            node = q.popleft()

            for neighbor in graph[node]:
                reachable[node][neighbor] = 1
                for i in range(numCourses):
                    if reachable[i][node]:
                        reachable[i][neighbor] = 1

                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)

        return [bool(reachable[query[0]][query[1]]) for query in queries]
