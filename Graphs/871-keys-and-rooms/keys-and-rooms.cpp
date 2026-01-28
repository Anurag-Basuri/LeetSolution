class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);

        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            if(visited[i] != 0) continue;
            visited[i]++;

            for(int key:rooms[i]) q.push(key);
        }

        int sum = 0;
        for(int i:visited) sum += i;

        return sum == n;
    }
};