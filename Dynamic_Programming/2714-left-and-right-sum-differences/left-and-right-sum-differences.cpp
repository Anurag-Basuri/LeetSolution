class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int con = 0;
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {
            con += nums[i];
            ans[i] = abs(sum - con);
            sum -= nums[i];
        }

        return ans;
    }
};