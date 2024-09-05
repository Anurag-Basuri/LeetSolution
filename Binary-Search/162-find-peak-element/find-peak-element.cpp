class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        if(right == 0) return 0;
        if(nums[left] > nums[left + 1]) return left;
        if(nums[right] > nums[right - 1]) return right;

        left = 1;
        right = right - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) return mid;
            else if(nums[mid - 1] > nums[mid]) right = mid - 1;
            else left = mid + 1;
        }

        return -1;
    }
};