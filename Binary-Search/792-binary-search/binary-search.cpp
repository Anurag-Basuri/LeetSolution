class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1, i = 0;

        while(i <= n){
            int mid = i + (n - i)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) i = mid + 1;
            else n = mid - 1;
        }

        return -1;
    }
};