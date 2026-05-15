class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;

        if(nums[i] < nums[j]) return nums[i];

        while(i < j) {
            int x = i + (j - i) / 2;

            if(nums[x] > nums[j]) i = x + 1;
            else j = x;
        }

        return nums[i];
    }
};