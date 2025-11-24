class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int mod = 0;
        vector<bool> ans;

        for(int i:nums) {
            int actual = (mod << 1) + i;

            mod = actual % 5;
            ans.push_back(mod == 0);
        }

        return ans;
    }
};