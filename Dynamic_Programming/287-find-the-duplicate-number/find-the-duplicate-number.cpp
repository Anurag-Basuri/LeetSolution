class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> store;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(store.find(nums[i]) != store.end()) return nums[i];

            store.insert(nums[i]);
        }

        return -1;
    }
};