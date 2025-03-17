class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> check;

        for(int i = 0; i < nums.size(); i++){
            if(check.count(nums[i]) > 0) check.erase(nums[i]);
            else check.insert(nums[i]);
        }

        return check.empty();
    }
};