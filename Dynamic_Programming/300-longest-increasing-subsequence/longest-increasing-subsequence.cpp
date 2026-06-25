class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        int ans = 1;

        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < i; j++) {
                if(nums[i - 1] > nums[j - 1] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};