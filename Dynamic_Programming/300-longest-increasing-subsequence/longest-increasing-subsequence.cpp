class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1e9);

        int len = 0;

        for(int i = 0; i < n; i++) {
            int low = 0;
            int high = len; 

            while(low < high) {
                int mid = low + (high - low) / 2;

                if(dp[mid] >= nums[i]) high = mid;
                else low = mid + 1;
            }

            dp[low] = nums[i];

            if(low == len) len++;
        }

        return len;
    }
};