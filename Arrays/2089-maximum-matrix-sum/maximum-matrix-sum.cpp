class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e5+7;
        long long totalSum = 0;
        bool isOdd = false;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int ele = abs(matrix[i][j]);
                totalSum += ele;
                mini = min(mini, ele);
                if(matrix[i][j] < 0) isOdd = !isOdd;
            }
        }

        if(isOdd) totalSum -= 2*mini;
        return totalSum;
    }
};