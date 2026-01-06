class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long sum = 0;
        int count = 0;
        int min_val = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sum += abs(matrix[i][j]);

                if(matrix[i][j] < 0) count++;

                min_val = min(min_val, abs(matrix[i][j]));
            }
        }

        if(count & 1) sum -= 2 * abs(min_val);

        return sum;
    }
};