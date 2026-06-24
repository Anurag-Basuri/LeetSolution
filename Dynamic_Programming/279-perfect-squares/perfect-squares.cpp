class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));

        for (int i = 0; i <= m; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= m; i++) {
            int square = i * i;

            for (int target = 1; target <= n; target++) {
                dp[i][target] = dp[i - 1][target];

                if (target >= square)
                    dp[i][target] =
                        min(dp[i][target], 1 + dp[i][target - square]);
            }
        }

        return dp[m][n];
    }
};