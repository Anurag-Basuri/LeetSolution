class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        long int xor_sum = 0, cur_sum = 0;
        int i = 0, j = 0;
        int n = nums.size();
        int max_len = 0;

        while (i < n && j < n) {
            xor_sum ^= nums[j];
            cur_sum += nums[j];

            if (xor_sum != cur_sum) {
                xor_sum ^= nums[i];
                cur_sum -= nums[i];
                i++;
            }

            max_len = max(j - i + 1, max_len);
            j++;
        }

        return max_len;
    }
};