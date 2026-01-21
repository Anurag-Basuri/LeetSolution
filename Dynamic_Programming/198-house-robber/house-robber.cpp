class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        int a = 0;
        int b = nums[0];

        for (int i = 1; i < n; i++) {
            int c = max(b, a + nums[i]);
            a = b;
            b = c;
        }

        return b;
    }
};