class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t1 = s;
        string t2 = s;
        reverse(t2.begin(), t2.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(t1[i - 1] == t2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }
};