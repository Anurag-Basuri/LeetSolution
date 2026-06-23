class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, maxCount = 0, curCount = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] == 1)
                curCount++;
            else
                curCount = 0;

            maxCount = max(maxCount, curCount);
            i++;
        }

        return maxCount;
    }
};