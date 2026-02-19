class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<int> dp(m, 0);

        dp[0] = (obstacleGrid[0][0] == 0);

        for(int j = 1; j < m; j++) {
            if(obstacleGrid[0][j] == 1)
                dp[j] = 0;
            else
                dp[j] = dp[j - 1];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else if(j > 0)
                    dp[j] += dp[j - 1];
            }
        }

        return dp[m - 1];
    }
};
