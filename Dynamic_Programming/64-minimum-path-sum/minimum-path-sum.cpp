class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dp(m, 0);
        for(int i = 0; i < m; i++) {
            if(i == 0) dp[i] = grid[0][i];
            else dp[i] = dp[i - 1] + grid[0][i];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(j > 0)
                    dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
                else 
                    dp[j] += grid[i][j];
            }
        }

        return dp[m - 1];
    }
};