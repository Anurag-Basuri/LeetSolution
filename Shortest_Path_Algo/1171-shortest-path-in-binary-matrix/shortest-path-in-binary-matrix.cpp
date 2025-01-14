class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Check if start or end cell is blocked
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }

        // Directions for 8 possible moves
        vector<pair<int, int>> directions = {
            {0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
        };

        // BFS queue: {row, col, distance}
        queue<vector<int>> q;
        q.push({0, 0, 1});

        // Visited array
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int row = cur[0];
            int col = cur[1];
            int dist = cur[2];

            // If we reach the bottom-right cell, return the distance
            if (row == n - 1 && col == n - 1) {
                return dist;
            }

            // Explore all 8 directions
            for (auto& d : directions) {
                int newRow = row + d.first;
                int newCol = col + d.second;

                // Check if the new cell is valid and unvisited
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0 && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = true; // Mark as visited
                    q.push({newRow, newCol, dist + 1});
                }
            }
        }

        // If no path is found, return -1
        return -1;
    }
};
