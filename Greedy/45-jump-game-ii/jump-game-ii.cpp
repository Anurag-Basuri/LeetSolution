class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 0, r = 0, jumps = 0;

        while (r < n) {
            int jr = r;
            for (int i = l; i <= r; i++) {
                jr = max(jr, i + nums[i]);
            }
            l = r + 1;
            r = jr;
            jumps++;
        }

        return jumps;
    }
};
