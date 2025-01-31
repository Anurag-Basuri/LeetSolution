class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> effort(rows, vector<int>(cols, 1e9));
        effort[0][0] = 0;

        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            
            int currEffort = current[0];
            int row = current[1];
            int col = current[2];

            if (row == rows - 1 && col == cols - 1) {
                return currEffort;
            }

            for (auto dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int diff = abs(heights[row][col] - heights[newRow][newCol]);
                    int maxEffort = max(currEffort, diff);

                    if (maxEffort < effort[newRow][newCol]) {
                        effort[newRow][newCol] = maxEffort;
                        pq.push({maxEffort, newRow, newCol});
                    }
                }
            }
        }
        return 0;
    }
};
