class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if the middle element is the target
            if (nums[mid] == target) {
                return true;
            }

            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
            }
            // Determine if the left half is sorted
            else if (nums[left] <= nums[mid]) {
                // Check if the target is in the left half
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                // Check if the target is in the right half
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        // Target not found
        return false;
    }
};
