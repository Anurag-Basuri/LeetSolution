class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int l = nums.size(), count = 0;
        for(int i = 0; i < l; i++)
            if(nums[i] % 3 != 0) count++;

        return count;
    }
};