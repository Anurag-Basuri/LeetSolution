class Solution:
    def dfs(self, preList, node, vis, ans):
        if vis[node] == 1:
            return True
        if vis[node] == 2:
            return False

        vis[node] = 1

        for next_node in preList[node]:
            if self.dfs(preList, next_node, vis, ans):
                return True

        vis[node] = 2
        ans.append(node)
        return False

    def findOrder(self, numCourses, prerequisites):
        preList = [[] for _ in range(numCourses)]

        for prereq in prerequisites:
            preList[prereq[0]].append(prereq[1])

        vis = [0] * numCourses
        ans = []

        for i in range(numCourses):
            if vis[i] == 0:
                if self.dfs(preList, i, vis, ans):
                    return []

        return ans