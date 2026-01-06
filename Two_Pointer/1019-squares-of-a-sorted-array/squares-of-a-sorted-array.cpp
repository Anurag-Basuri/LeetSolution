class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, pos = nums.size(), r = nums.size() - 1;
        vector<int> ans(pos--);

        while(l <= r){
            int a = nums[l] * nums[l];
            int b = nums[r] * nums[r];

            if(a > b){
                ans[pos--] = a;
                l++;
            }
            else{
                ans[pos--] = b;
                r--;
            }
        }

        return ans;
    }
};