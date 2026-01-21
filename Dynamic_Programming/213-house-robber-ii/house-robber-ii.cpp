class Solution {
public:
    int check(vector<int>& nums) {
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

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> range1(nums.begin(), nums.end() - 1);
        int a = check(range1);

        vector<int> range2(nums.begin() + 1, nums.end());
        int b = check(range2);

        return max(a, b);
    }
};