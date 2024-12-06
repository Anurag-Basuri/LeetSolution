class Solution {
public:
    void dfs(vector<vector<int>>& vis, vector<vector<char>>& board, int sr,
             int sc, int n, int m) {
        if (sr < 0 || sr >= n || sc < 0 || sc >= m || vis[sr][sc] == 1 ||
            board[sr][sc] != 'O')
            return;

        vis[sr][sc] = 1;
        dfs(vis, board, sr - 1, sc, n, m);
        dfs(vis, board, sr + 1, sc, n, m);
        dfs(vis, board, sr, sc - 1, n, m);
        dfs(vis, board, sr, sc + 1, n, m);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O')
                dfs(vis, board, 0, i, n, m);

            if (board[n - 1][i] == 'O')
                dfs(vis, board, n - 1, i, n, m);
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(vis, board, i, 0, n, m);

            if (board[i][m - 1] == 'O')
                dfs(vis, board, i, m - 1, n, m);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 1 && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};