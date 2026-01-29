class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        int time = 0;

        while(!q.empty() && fresh > 0) {
            int size = q.size();
            bool rotted = false;

            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(auto d : dir) {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        rotted = true;
                        q.push({nx, ny});
                    }
                }
            }

            if(rotted) time++;
        }

        return fresh == 0 ? time : -1;
    }
};
