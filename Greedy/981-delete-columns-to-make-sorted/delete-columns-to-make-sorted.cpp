class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int deletionCount = 0;

        // Iterate through each column first
        for (int j = 0; j < cols; j++) {
            for (int i = 1; i < rows; i++) {
                // If we find a pair that isn't non-decreasing
                if (strs[i-1][j] > strs[i][j]) {
                    deletionCount++;
                    break; // Move to the next column immediately
                }
            }
        }

        return deletionCount;
    }
};