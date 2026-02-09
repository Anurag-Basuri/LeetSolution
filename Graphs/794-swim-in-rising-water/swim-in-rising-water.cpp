class Solution {
public:
    int n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool dfs(int i, int j, int t, vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {

        if (i < 0 || j < 0 || i >= n || j >= n ||
            visited[i][j] || grid[i][j] > t) {
            return false;
        }

        if (i == n - 1 && j == n - 1) return true;

        visited[i][j] = true;

        for (auto& d : directions) {
            if (dfs(i + d[0], j + d[1], t, grid, visited))
                return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int low = grid[0][0];
        int high = n * n - 1;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            vector<vector<bool>> visited(n, vector<bool>(n, false));

            if (dfs(0, 0, mid, grid, visited)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
