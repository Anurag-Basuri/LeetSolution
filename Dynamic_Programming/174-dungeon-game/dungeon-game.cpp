class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case (princess cell)
        dp[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);

        // Last column
        for (int i = n - 2; i >= 0; i--) {
            dp[i][m - 1] = max(1, dp[i + 1][m - 1] - dungeon[i][m - 1]);
        }

        // Last row
        for (int j = m - 2; j >= 0; j--) {
            dp[n - 1][j] = max(1, dp[n - 1][j + 1] - dungeon[n - 1][j]);
        }

        // Remaining cells
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                int need = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(1, need - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};
