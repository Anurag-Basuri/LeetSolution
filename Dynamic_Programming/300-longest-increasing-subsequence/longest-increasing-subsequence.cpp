class Solution {
public:
    int f(int i, int prev, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if(i < 0) return 0;

        if(dp[i][prev] != -1) return dp[i][prev];

        int notTake = f(i - 1, prev, n, nums, dp);

        int take = 0;
        if(prev == n || nums[i] < nums[prev])
            take = 1 + f(i - 1, i, n, nums, dp);
        
        return dp[i][prev] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(n - 1, n, n, nums, dp);
    }
};