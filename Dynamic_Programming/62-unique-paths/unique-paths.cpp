class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(m, 1);

        // for(int i = 0; i < m; i++) dp[0][i] += 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(j >= 1) dp[j] += dp[j - 1];
            }
        }

        return dp[m - 1];
    }
};