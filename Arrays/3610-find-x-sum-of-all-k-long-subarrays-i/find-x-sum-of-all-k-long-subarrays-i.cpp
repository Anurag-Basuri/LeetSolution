class Solution {
private:
    int helper(vector<int> nums, int n, int x) {
        unordered_map<int, int> count;

        for(int i = 0; i < n; i++) 
            count[nums[i]]++;

        vector<pair<int, int>> arr;
        for(auto& a : count)
            arr.push_back(pair<int,int>{a.first, a.second});
        
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            if(a.second == b.second) return a.first > b.first;
            return a.second > b.second;
        });

        int sum = 0;
        for(int i = 0; i < arr.size() && i < x; i++)
            sum += arr[i].second * arr[i].first;
        
        return sum;
    }

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i <= n - k; i++) {
            vector<int> sub(nums.begin() + i, nums.begin() + i + k);
            ans.push_back(helper(sub, k, x));
        }

        return ans;
    }
};
