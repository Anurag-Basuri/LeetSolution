class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sum = 0;
        for(int num:nums) sum += num;

        int n = nums.size();
        vector<int> ans(n, 0);
        int leftSum = 0;

        for(int i = 0; i < n; i++) {
            leftSum += nums[i];
            sum -= nums[i];

            int x = (i + 1) * nums[i];
            int y = (n - i - 1) * nums[i];
            ans[i] = abs(leftSum - x) + abs(sum - y);
        }

        return ans;
    }
};