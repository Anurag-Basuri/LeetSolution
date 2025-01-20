class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> indices;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                indices[mat[i][j]] = {i, j};
            }
        }

        int l = arr.size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i = 0; i < l; i++){
            int x = indices[arr[i]].first;
            int y = indices[arr[i]].second;

            row[x]++;
            col[y]++;

            if(row[x] == n || col[y] == m) return i;
        }

        return -1;
    }
};