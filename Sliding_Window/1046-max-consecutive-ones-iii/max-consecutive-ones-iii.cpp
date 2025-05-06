class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), noz = 0, maxl = 0;
        int low = 0, high = 0;

        while(high < n){
            if(nums[high] == 0) noz++;

            if(noz > k){
                if(nums[low] == 0) noz--;
                low++;
            }

            if(noz <= k) maxl = max(maxl, high - low + 1);

            high++;
        }

        return maxl;
    }
};