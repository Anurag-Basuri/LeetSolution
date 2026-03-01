class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // dp[i][prevIndex + 1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int prevIndex = i - 1; prevIndex >= -1; prevIndex--) {

                int notTake = dp[i + 1][prevIndex + 1];

                int take = 0;
                if(prevIndex == -1 || nums[i] > nums[prevIndex])
                    take = 1 + dp[i + 1][i + 1];

                dp[i][prevIndex + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};