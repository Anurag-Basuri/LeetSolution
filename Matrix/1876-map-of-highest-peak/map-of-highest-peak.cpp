class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (auto dir : directions) {
                int newRow = dir[0] + row;
                int newCol = dir[1] + col;

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    ans[newRow][newCol] == -1) {
                    ans[newRow][newCol] = ans[row][col] + 1;

                    q.push({newRow, newCol});
                }
            }
        }

        return ans;
    }
};