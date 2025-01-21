class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int N = grid[0].size(); // Number of columns

        // Step 1: Precompute prefix sums
        vector<long long> top(N, 0);
        vector<long long> bottom(N, 0);

        // Top prefix sum from right to left
        top[N - 1] = grid[0][N - 1];
        for (int i = N - 2; i >= 0; i--) {
            top[i] = grid[0][i] + top[i + 1];
        }

        // Bottom prefix sum from left to right
        bottom[0] = grid[1][0];
        for (int i = 1; i < N; i++) {
            bottom[i] = grid[1][i] + bottom[i - 1];
        }

        // Step 2: Calculate the minimum maximum score for Player 2
        long long result = LLONG_MAX; // Initialize with a very large value

        for (int i = 0; i < N; i++) {
            // Player 2's possible scores
            long long scoreTop = (i + 1 < N) ? top[i + 1] : 0;  // Remaining top row sum
            long long scoreBottom = (i - 1 >= 0) ? bottom[i - 1] : 0; // Remaining bottom row sum

            // Max score Player 2 can achieve at this point
            long long player2Score = max(scoreTop, scoreBottom);

            // Minimize the max score for Player 2
            result = min(result, player2Score);
        }

        return result;
    }
};
