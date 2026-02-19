class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return grid[i][j];

        if(dp[i][j]) return dp[i][j];

        int top = 1e9;
        if(i - 1 >= 0) top = grid[i][j] + f(i - 1, j, grid, dp);

        int left = 1e9;
        if(j - 1 >= 0) left = grid[i][j] + f(i , j - 1, grid, dp);

        return dp[i][j] = min(left, top);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        return f(n - 1, m - 1, grid, dp);
    }
};