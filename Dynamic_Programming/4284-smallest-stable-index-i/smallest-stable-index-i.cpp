class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int sum = INT_MAX, n = nums.size();
        int min = nums[0];
        int max = nums[0];

        for(int i = 0; i < n; i++) {
            if(nums[i] > max) max = nums[i];
            min = *min_element(nums.begin() + i, nums.end());

            if(max - min <= k)
                return i;
        }

        return -1;
    }
};