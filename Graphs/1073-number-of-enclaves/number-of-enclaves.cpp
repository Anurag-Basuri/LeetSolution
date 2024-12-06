class Solution {
public:
    void dfs(vector<vector<int>>& vis, vector<vector<int>>& grid, int sr, int sc, int n, int m){
        if(sc < 0 || sc >= m || sr < 0 || sr >= n || vis[sr][sc] != 0 || grid[sr][sc] == 0)
            return;
        
        vis[sr][sc] = 1;

        dfs(vis, grid, sr - 1, sc, n, m);
        dfs(vis, grid, sr + 1, sc, n, m);
        dfs(vis, grid, sr, sc - 1, n, m);
        dfs(vis, grid, sr, sc + 1, n, m);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++){
            if(grid[0][i] == 1)
                dfs(vis, grid, 0, i, n,  m);
            
            if(grid[n-1][i] == 1)
                dfs(vis, grid, n-1, i, n,  m);
        }

        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1)
                dfs(vis, grid, i, 0, n,  m);
            
            if(grid[i][m-1] == 1)
                dfs(vis, grid, i, m-1, n,  m);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    ans++;
            }
        }

        return ans;
    }
};