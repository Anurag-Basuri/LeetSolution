class Solution {
public:
    int binSearch(vector<int>& nums, int target, int lor){
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else{
                ans = mid;
                if(lor == 1)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);

        ans[0] = binSearch(nums, target, 1);
        if(ans[0] != -1) {
            ans[1] = binSearch(nums, target, 0);
        }

        return ans;
    }
};