class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
        int n = coins.size();
        int inf = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, inf));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];

                if (coins[i - 1] <= j) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }

        return dp[n][m] == inf? -1:dp[n][m];
    }
};