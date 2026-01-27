class Solution {
public:
    int recur(int i, vector<int>& nums, unordered_map<int, int>& dp) {
        if (i < 0) return 0;
        if (i == 0) return nums[0];

        if (dp.find(i) != dp.end())
            return dp[i];

        int notTake = recur(i - 1, nums, dp);
        int take = recur(i - 2, nums, dp) + nums[i];

        return dp[i] = max(notTake, take);
    }

    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> dp;
        return recur(nums.size() - 1, nums, dp);
    }
};
