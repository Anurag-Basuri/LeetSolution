class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_len = 0, count = 0;
        int min_n = nums[0], max_n = nums[0];
        int i = 0, j = 0, n = nums.size();

        while(i < n && j < n) {
            for(j; j < n && nums[j] - nums[i] <= 1; j++)
                if(nums[j] - nums[i] == 1) count = j - i + 1; 
        
            max_len = max(count, max_len);
            count = 0;
            i++;
        }

        return max_len;
    }
};