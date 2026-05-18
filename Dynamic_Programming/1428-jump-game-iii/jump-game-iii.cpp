class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0)
            return true;

        int n = arr.size();
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(start);

        while (!q.empty()) {
            int a = q.front();
            q.pop();

            if (a >= 0 && a < n && !vis[a]) {
                if (arr[a] == 0)
                    return true;
                else {
                    int x = a + arr[a];
                    q.push(x);
                    int y = a - arr[a];
                    q.push(y);

                    vis[a] = 1;
                }
            }

        }

        return false;
    }
};