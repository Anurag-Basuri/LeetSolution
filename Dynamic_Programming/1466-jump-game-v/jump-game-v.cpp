class Solution {
public:
    int recur(int idx, vector<int>& arr, vector<int>& dp, int n, int d) {
        if (dp[idx] != -1)
            return dp[idx];

        int ans = 1;

        for (int i = idx + 1; i <= min(idx + d, n - 1); i++) {
            if (arr[i] >= arr[idx])
                break;

            ans = max(ans, 1 + recur(i, arr, dp, n, d));
        }

        for (int i = idx - 1; i >= max(0, idx - d); i--) {
            if (arr[i] >= arr[idx])
                break;

            ans = max(ans, 1 + recur(i, arr, dp, n, d));
        }

        return dp[idx] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 1;

        for (int i = 0; i < n; i++)
            ans = max(ans, recur(i, arr, dp, n, d));

        return ans;
    }
};