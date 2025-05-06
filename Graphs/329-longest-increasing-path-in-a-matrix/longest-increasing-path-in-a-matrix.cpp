class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memory, int i, int j, vector<pair<int, int>>& directions) {
        if (memory[i][j] != -1) {
            return memory[i][j];
        }

        int max_path = 1;

        for (auto& dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j]) {
                max_path = max(max_path, 1 + dfs(matrix, memory, x, y, directions));
            }
        }

        memory[i][j] = max_path;
        return max_path;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memory(m, vector<int>(n, -1));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, memory, i, j, directions));
            }
        }

        return ans;
    }
};
