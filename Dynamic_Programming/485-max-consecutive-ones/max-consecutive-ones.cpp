class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, maxCount = 0, curCount = 0;
        int n = nums.size();

        while(i < n ) {
            if(nums[i] == 1) {
                curCount++;
            } else {
                maxCount = max(maxCount, curCount);
                curCount = 0;
            }

            i++;
        }

        maxCount = max(maxCount, curCount);

        return maxCount;
    }
};