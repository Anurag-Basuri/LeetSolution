class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == 0) return 0;

        visited[i][j] = 1;

        int area = grid[i][j];
        area += dfs(i + 1, j, grid, visited, n, m);
        area += dfs(i - 1, j, grid, visited, n, m);
        area += dfs(i, j + 1, grid, visited, n, m);
        area += dfs(i, j - 1, grid, visited, n, m);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int area = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                if(visited[i][j] == 0 && grid[i][j] == 1) area = max(area, dfs(i, j, grid, visited, n, m));
        }

        return area;
    }
};