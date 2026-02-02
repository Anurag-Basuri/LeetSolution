class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, itr;

        while(itr <= right) {
            if(nums[itr] == 0) swap(nums[itr++], nums[left++]);
            else if(nums[itr] == 2) swap(nums[itr], nums[right--]);
            else itr++;
        }
    }
};