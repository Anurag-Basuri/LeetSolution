class Solution {
public:
    void backTrack(int i, vector<int> &can, vector<vector<int>> &ans,
                   vector<int> &cur, int tar, vector<vector<int>> &dp) {

        if (tar == 0) {
            ans.push_back(cur);
            return;
        }

        if (i < 0 || tar < 0) return;

        // invalid repeated state
        if (dp[i][tar] == 0) return;

        int before = ans.size();

        // pick current element
        if (tar >= can[i]) {
            cur.push_back(can[i]);
            backTrack(i, can, ans, cur, tar - can[i], dp);
            cur.pop_back();
        }

        // skip current element
        backTrack(i - 1, can, ans, cur, tar, dp);

        if (ans.size() == before) {
            dp[i][tar] = 0;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        int n = can.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        vector<vector<int>> ans;
        vector<int> cur;

        backTrack(n - 1, can, ans, cur, target, dp);
        return ans;
    }
};
