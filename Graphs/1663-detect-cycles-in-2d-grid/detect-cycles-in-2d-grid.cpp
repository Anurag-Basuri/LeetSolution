class Solution {
public:
    bool dfs(int i, int j, int n, int m, int px, int py,
             vector<vector<char>>& grid, vector<vector<int>>& visited) {
        visited[i][j] = 1;

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (auto& dir : dirs) {
            int x = i + dir.first;
            int y = j + dir.second;

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == grid[i][j]){
                if (visited[x][y] && (x != px || y != py))
                    return true;

                if (!visited[x][y] && dfs(x, y, n, m, i, j, grid, visited))
                    return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, n, m, -1, -1, grid, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};