class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        if(n == 1) return 0;

        vector<int> check(m, 0);

        for (int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(strs[i-1][j] - strs[i][j] >= 1) check[j] = 1; 
            }
        }

        int c = 0;
        for(int i:check) c += i; 

        return c;
    }
};