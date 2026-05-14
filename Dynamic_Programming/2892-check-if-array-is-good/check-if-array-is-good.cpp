class Solution {
public:
    bool isGood(vector<int>& nums) {
        int l = nums.size();
        unordered_map<int, int> check;
        int mx = 0;

        for(int i:nums) {
            mx = max(i, mx);

            check[i]++;

            if(check[i] > 2) return false;
            else if(check[i] == 2)
                if(i != l - 1) return false;
            
        }

        if(mx != l - 1) return false;

        return true;
    }
};