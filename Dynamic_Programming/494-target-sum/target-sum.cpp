class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If target is unreachable
        if (abs(target) > totalSum) return 0;

        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, 0));

        // Base case (i = 0)
        dp[0][ nums[0] + totalSum ] += 1;
        dp[0][ -nums[0] + totalSum ] += 1;

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int s = -totalSum; s <= totalSum; s++) {
                if (dp[i - 1][s + totalSum] > 0) {
                    dp[i][s + nums[i] + totalSum] += dp[i - 1][s + totalSum];
                    dp[i][s - nums[i] + totalSum] += dp[i - 1][s + totalSum];
                }
            }
        }

        return dp[n - 1][target + totalSum];
    }
};
