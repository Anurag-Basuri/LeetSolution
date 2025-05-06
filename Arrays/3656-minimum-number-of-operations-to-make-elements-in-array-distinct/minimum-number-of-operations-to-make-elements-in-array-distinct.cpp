class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;

        while(true){
            unordered_set<int> unique(nums.begin(), nums.end());

            if(unique.size() == nums.size()) return ops;

            if(nums.size() < 3) nums.clear();
            else nums.erase(nums.begin(), nums.begin() + 3);

            ops++;
        }

        return 1;
    }
};