class Solution {
public:
    int recur(int i, int j, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return 1;

        if(dp[i][j]) return dp[i][j];

        int top = 0;
        if(i - 1 >= 0) top = recur(i - 1, j, dp);

        int left = 0;
        if(j - 1 >= 0) left = recur(i, j - 1, dp);

        return dp[i][j] = top + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(n , vector<int>(m, 0));

        return recur(n - 1, m - 1, grid);
    }
};