class Solution {
public:
    int dfs(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& memo) {
        // Base case: last row
        if (i == n - 1)
            return triangle[i][j];

        // Already computed
        if (memo[i][j] != INT_MAX)
            return memo[i][j];

        // Recursive calls
        int down = dfs(i + 1, j, n, triangle, memo);
        int diag = dfs(i + 1, j + 1, n, triangle, memo);

        return memo[i][j] = triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);

        for(int i = 0; i < n; i++)
            dp[i] = vector<int>(triangle[i].size(), INT_MAX);

        return dfs(0, 0, n, triangle, dp);
    }
};