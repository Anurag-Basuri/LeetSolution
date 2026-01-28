class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid,
            vector<vector<int>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m ||
            grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }

        visited[i][j] = 1;

        int area = 1;

        area += dfs(i + 1, j, grid, visited);
        area += dfs(i - 1, j, grid, visited);
        area += dfs(i, j + 1, grid, visited);
        area += dfs(i, j - 1, grid, visited);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int max_area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = dfs(i, j, grid, visited);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};
