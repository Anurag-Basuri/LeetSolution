class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n);

        int maxLen = 0;
        int lastIdx = 0;

        for (int i = 0; i < n; i++) {
            parent[i] = i;

            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if (maxLen < dp[i]) {
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        vector<int> ans;
        while (parent[lastIdx] != lastIdx) {
            ans.push_back(nums[lastIdx]);
            lastIdx = parent[lastIdx];
        }

        ans.push_back(nums[lastIdx]);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};