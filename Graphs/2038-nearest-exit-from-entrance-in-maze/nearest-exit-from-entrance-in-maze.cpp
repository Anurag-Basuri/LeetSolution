class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});

        // Mark entrance as visited
        maze[entrance[0]][entrance[1]] = '+';

        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        int steps = 0;

        while(!q.empty()) {
            int size = q.size();
            steps++;

            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(auto d : dir) {
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == '.') {

                        // Exit condition
                        if(nx == 0 || ny == 0 || nx == n-1 || ny == m-1)
                            return steps;

                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};
