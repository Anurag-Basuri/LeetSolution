class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);

        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= m; i++) {
            int square = i * i;

            for (int target = 1; target <= n; target++) {
                if (target >= square)
                    dp[target] = min(dp[target], dp[target - square] + 1);
            }
        }

        return dp[n];
    }
};