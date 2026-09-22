class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += *max_element(mat[i].begin(), mat[i].end());
        
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        dp[0][0] = true;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(!dp[i][j]) continue;

                for(int k = 0; k < m; k++)
                    dp[i + 1][j + mat[i][k]] = true;
            }
        }

        int minVal = 1e9;
        for(int i = 0; i <= sum; i++) {
            if(dp[n][i])
                minVal = min(minVal, abs(target - i));
        }

        return minVal;
    }
};