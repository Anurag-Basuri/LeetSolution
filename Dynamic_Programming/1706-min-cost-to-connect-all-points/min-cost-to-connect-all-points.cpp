class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int min_cost = 0;
        vector<int> visited(n, false);

        priority_queue < pair<int, int>,
            vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int u = it.second;
            if (visited[u])
                continue;

            visited[u] = true;
            min_cost += it.first;

            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    int dist = abs(points[i][0] - points[u][0]) +
                               abs(points[i][1] - points[u][1]);
                    
                    pq.push({dist, i});
                }
            }
        }

        return min_cost;
    }
};