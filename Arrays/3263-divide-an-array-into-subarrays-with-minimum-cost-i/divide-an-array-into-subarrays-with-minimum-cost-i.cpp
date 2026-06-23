class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int a = nums[1], b = nums[2];

        for(int i = 3; i < n; i++) {
            int x = nums[i];
            int t;
            if(x < a) {
                t = x;
                x = a;
                a = t;
            }
            
            if(x < b) {
                t = x;
                x = b;
                b = t;
            }
        }

        return nums[0] + a + b;
    }
};