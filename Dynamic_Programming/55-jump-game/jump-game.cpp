class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = 0;

        for(int i = 0; i < n; i++) {
            if(i > maxJump) return false;

            maxJump = max(i + nums[i], maxJump);

            if(maxJump >= n - 1) return true;
        }

        return false;
    }
};