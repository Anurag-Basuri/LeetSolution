class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefixSum = 0;
        int maxSum = 0;
        int minSum = 0;

        for(int num:nums){
            prefixSum += num;

            maxSum = max(maxSum, prefixSum);
            minSum = min(minSum, prefixSum);
        }

        return maxSum - minSum;
    }
};