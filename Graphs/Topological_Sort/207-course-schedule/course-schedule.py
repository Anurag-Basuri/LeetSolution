class Solution:
    def dfs(self, preList, node, vis):
        if vis[node] == 1:
            return True
            
        if vis[node] == 2:
            return False

        vis[node] = 1

        for neighbor in preList[node]:
            if self.dfs(preList, neighbor, vis):
                return True

        vis[node] = 2

        return False

    def canFinish(self, numCourses, prerequisites):
        preList = [[] for _ in range(numCourses)]

        for course, prereq in prerequisites:
            preList[course].append(prereq)

        vis = [0] * numCourses

        for i in range(numCourses):
            if vis[i] == 0 and self.dfs(preList, i, vis):
                return False

        return True
