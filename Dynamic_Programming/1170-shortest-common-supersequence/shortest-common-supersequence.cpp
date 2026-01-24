class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // LCS DP
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Reconstruct SCS
        int i = n, j = m;
        string st = "";

        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                st += text1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                st += text1[i - 1];
                i--;
            } else {
                st += text2[j - 1];
                j--;
            }
        }

        // Append remaining characters
        while (i > 0) {
            st += text1[i - 1];
            i--;
        }
        while (j > 0) {
            st += text2[j - 1];
            j--;
        }

        reverse(st.begin(), st.end());
        return st;
    }
};
