class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, vector<int>& ans,
             int node) {
        if (vis[node] == 2)
            return true;

        if(vis[node] == 1)
            return false;

        vis[node] = 1;

        for (auto i : graph[node]) {
            if (!dfs(graph, vis, ans, i))
                return false;
        }

        vis[node] = 2;
        ans.push_back(node);
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0)
                dfs(graph, vis, ans, i);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};