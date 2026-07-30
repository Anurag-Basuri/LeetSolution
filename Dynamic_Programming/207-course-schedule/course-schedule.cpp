class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        int visited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;
            
            for (int neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }
        
        return visited == numCourses;
    }
};
