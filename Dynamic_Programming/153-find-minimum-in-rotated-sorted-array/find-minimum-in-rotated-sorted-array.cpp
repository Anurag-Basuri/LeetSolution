class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;


        while(left < right) {
            int x = left + (right - left) / 2;

            if(nums[left] < nums[right]) return nums[left];
            
            if(nums[x] >= nums[left]) left = x + 1;
            else right = x;
        }

        return nums[left];
    }
};