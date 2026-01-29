class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        // Multi-source BFS initialization
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(auto d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && ans[nx][ny] == -1) {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};
