class Solution {
public:
    int f(int m, int target, int idx, int sum, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        if(idx < 0) return abs(target - sum);

        if(dp[idx][sum] != -1) return dp[idx][sum];

        int val = 1e9;

        for(int i = 0; i < m; i++) {
            val = min(val, f(m, target, idx - 1, sum + mat[idx][i], mat, dp));
        }

        return dp[idx][sum] = val;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        int maxSum = 0;

        for(int i = 0; i < n; i++)
            maxSum += *max_element(mat[i].begin(), mat[i].end());

        vector<vector<int>> dp(n, vector<int>(maxSum + 1, -1));

        return f(m, target, n - 1, 0, mat, dp);
    }
};