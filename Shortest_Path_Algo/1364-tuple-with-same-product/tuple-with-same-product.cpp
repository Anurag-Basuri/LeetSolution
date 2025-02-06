class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++)
                mp[nums[i] * nums[j]]++;
        }

        int ans = 0;

        for(auto pair:mp){
            if(pair.second >= 2){
                int num = pair.second;
                ans += (num*(num - 1)/2)*8;
            }
        }

        return ans;
    }
};