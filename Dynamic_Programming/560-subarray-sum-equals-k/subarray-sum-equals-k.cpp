class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> store;
        store[0] = 1;
        int n = nums.size();
        int sum = 0;
        int total = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int dif = sum - k;

            if(store.find(dif) != store.end())
                total += store[dif];
            
            store[sum]++;
        }

        return total;
    }
};