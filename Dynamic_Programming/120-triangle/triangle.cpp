class Solution {
public:
    int travel(int level, int m, int index, 
               vector<vector<int>>& triangle, 
               vector<vector<int>>& dp) {
        
        // Base case: last row
        if(level == m - 1) 
            return triangle[level][index];

        // If already computed
        if(dp[level][index] != INT_MAX) 
            return dp[level][index];
        
        // Recursive relation
        dp[level][index] = triangle[level][index] + 
            min(travel(level + 1, m, index, triangle, dp),
                travel(level + 1, m, index + 1, triangle, dp));

        return dp[level][index];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        // DP initialization
        vector<vector<int>> dp(m);
        for(int i = 0; i < m; i++) {
            dp[i] = vector<int>(triangle[i].size(), INT_MAX);
        }

        // Start from top
        return travel(0, m, 0, triangle, dp);    
    }
};