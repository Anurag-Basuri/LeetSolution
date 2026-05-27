class Solution {
public:
    int recur(int idx, vector<int>& nums, vector<int>& dp, int n) {
        if(idx >= n - 1)
            return 0;

        if(dp[idx])
            return dp[idx];
        
        int ans = 1e7;
        for(int i = 1; i <= nums[idx]; i++) {
            if((i + idx) < n)
                ans = min(ans, 1 + recur(i + idx, nums, dp, n));
        }

        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        return recur(0, nums, dp, n);
    }
};