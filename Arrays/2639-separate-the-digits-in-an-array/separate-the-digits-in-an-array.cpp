class Solution {
public:
    void sep(int digit, vector<int>& ans) {
        auto x = ans.size();
        int a;

        while(digit != 0) {
            a = digit % 10;
            ans.push_back(a);
            digit = digit / 10;
        }

        reverse(ans.begin() + x, ans.end());

        return;
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int i:nums) {
            sep(i, ans);
        }

        return ans;
    }
};