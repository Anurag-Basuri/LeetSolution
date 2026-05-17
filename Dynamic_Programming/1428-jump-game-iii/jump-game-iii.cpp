class Solution {
public:
    bool dfs(vector<int>& arr, vector<int>& visited, int n, int i) {
        if(arr[i] == 0) return true;

        visited[i] = 1;

        bool ans = false;

        int i1 = i + arr[i];
        if(i1 >= 0 && i1 < n && !visited[i1])
            ans = ans || dfs(arr, visited, n, i1);
        
        int i2 = i - arr[i];    
        if(i2 >= 0 && i2 < n && !visited[i2])
            ans = ans || dfs(arr, visited, n, i2);
        
        return ans;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n, 0);

        return dfs(arr, visited, n, start);
    }
};