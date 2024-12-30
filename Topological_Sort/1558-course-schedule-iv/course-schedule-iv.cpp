class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<vector<int>> reachable(numCourses, vector<int>(numCourses, 0));
        vector<int> indegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neighbor : graph[node]) {
                reachable[node][neighbor] = 1;
                for (int i = 0; i < numCourses; i++) {
                    if (reachable[i][node]) reachable[i][neighbor] = 1;
                }

                if (--indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        vector<bool> ans;
        for (auto& query : queries) {
            ans.push_back(reachable[query[0]][query[1]]);
        }
        return ans;
    }
};
