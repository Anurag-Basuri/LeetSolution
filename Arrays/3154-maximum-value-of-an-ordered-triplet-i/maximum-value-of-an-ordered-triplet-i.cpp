class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long max_i = nums[0], i_minus_j = -1e9, max_sum = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            i_minus_j = max(i_minus_j, max_i - nums[i]);
            max_i = max(max_i, (long long)nums[i]);
            max_sum = max(max_sum, i_minus_j * nums[i + 1]);
        }

        return max_sum;
    }
};