class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        if (amount == 0) return 1;
        if (n == 0) return 0;

        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

        // base case
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                __int128 notTaken = dp[i - 1][j];
                __int128 taken = 0;

                if (coins[i] <= j)
                    taken = dp[i][j - coins[i]];

                dp[i][j] = (long long)(notTaken + taken);
            }
        }

        return (int)dp[n - 1][amount];
    }
};
