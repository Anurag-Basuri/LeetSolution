class Solution {
public:
    int totalSum;

    int f(int i, vector<int> &nums, vector<vector<int>> &dp, int target, int currSum) {
        if (i < 0)
            return currSum == target;

        if (dp[i][currSum + totalSum] != -1)
            return dp[i][currSum + totalSum];

        int add = f(i - 1, nums, dp, target, currSum + nums[i]);
        int sub = f(i - 1, nums,  dp,target, currSum - nums[i]);

        return dp[i][currSum + totalSum] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<int>> memo(n, vector<int>(2 * totalSum + 1, -1));
        return f(n - 1, nums, memo,target, 0);
    }
};
