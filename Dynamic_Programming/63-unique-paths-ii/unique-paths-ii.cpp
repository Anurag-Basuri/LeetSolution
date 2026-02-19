class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(grid[i][j] == 1) return 0;

        if(i == 0 && j == 0) return 1;

        if(dp[i][j]) return dp[i][j];

        int top = 0;
        if(i - 1 >= 0) top = f(i - 1, j, grid, dp);

        int left = 0;
        if(j - 1 >= 0) left = f(i, j - 1, grid, dp);

        return dp[i][j] = top + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n , vector<int>(m, 0));

        return f(n - 1, m - 1, obstacleGrid, dp);
    }
};