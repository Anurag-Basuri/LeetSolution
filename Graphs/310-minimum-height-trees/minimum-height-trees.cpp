class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};

        // Build adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Initialize the queue with all leaf nodes
        vector<int> vis(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) { // Leaf nodes have only one connection
                q.push(i);
                vis[i] = 1;
            }
        }

        // Perform BFS to find the roots of MHTs
        vector<int> prev;
        while (!q.empty()) {
            prev.clear(); // Keep track of the last layer (potential roots)
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                prev.push_back(node);

                for (int neighbor : adj[node]) {
                    if (vis[neighbor] <
                        adj[neighbor].size()) { // Process unvisited neighbors
                        vis[neighbor]++;

                        if (vis[neighbor] == adj[neighbor].size() -
                                                 1) // If it becomes a new leaf
                            q.push(neighbor);
                    }
                }
            }
        }

        // The last layer processed contains the root(s) of the MHT
        return prev;
    }
};
