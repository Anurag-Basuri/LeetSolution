class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for (const auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        queue<tuple<int, int, int>> q; // {current node, total cost, stops}
        q.push({src, 0, 0});

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        while (!q.empty()) {
            auto [cur, cost, stops] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto [nextNode, price] : graph[cur]) {
                if (cost + price < minCost[nextNode]) {
                    minCost[nextNode] = cost + price;
                    q.push({nextNode, cost + price, stops + 1});
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
