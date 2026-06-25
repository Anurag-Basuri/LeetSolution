class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
        int ans = 1;

        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < i + 1; j++) {
                dp[i][j] = dp[i][j - 1];

                if(nums[i - 1] > nums[j - 1] && dp[j][j - 1] + 1 > dp[i][j])
                    dp[i][j] = dp[j][j - 1] + 1;
            }

            ans = max(ans, dp[i][i - 1]);
        }

        return ans;
    }
};