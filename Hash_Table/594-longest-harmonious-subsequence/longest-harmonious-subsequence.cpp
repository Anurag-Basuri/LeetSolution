class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_len = 0, count = 0;
        int i = 0, j = 0, n = nums.size();

        for(j; j < n; j++) {
            while(nums[j] - nums[i] > 1)
                i++;
            
            if(nums[j] - nums[i] == 1)
                max_len = max(j-i+1, max_len);
        }

        return max_len;
    }
};