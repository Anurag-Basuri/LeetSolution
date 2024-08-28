class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int product = 1, ans = 0, i = 0, j = 0;

        while(i < nums.size()){
            product *= nums[i];

            while(product >= k){
                product = product / nums[j];
                j++;
            }

            ans += i - j + 1;
            i++;
        }

        return ans;
    }
};