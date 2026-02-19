class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++) dp[0][i] += 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = dp[i - 1][j];

                if(j >= 1) dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};