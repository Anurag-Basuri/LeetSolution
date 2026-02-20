class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // dp represents the minimum path sum to reach each column of current row
        vector<int> dp = matrix[0];

        for (int i = 1; i < n; i++) {
            vector<int> newDp(n, INT_MAX);

            for (int j = 0; j < n; j++) {
                // from directly above
                newDp[j] = min(newDp[j], dp[j] + matrix[i][j]);

                // from upper-left
                if (j > 0)
                    newDp[j] = min(newDp[j], dp[j - 1] + matrix[i][j]);

                // from upper-right
                if (j < n - 1)
                    newDp[j] = min(newDp[j], dp[j + 1] + matrix[i][j]);
            }

            dp = newDp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};