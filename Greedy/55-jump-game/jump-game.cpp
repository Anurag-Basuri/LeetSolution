class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxp = 0;

        for(int i = 0; i < n; i++){
            if(i > maxp) return false;

            maxp = max(i + nums[i], maxp);

            if(maxp > n - 1) return true;
        }

        return true;
    }
};