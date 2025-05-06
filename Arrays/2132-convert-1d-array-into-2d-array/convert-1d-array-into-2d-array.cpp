class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;

        if(m*n != original.size())
            return ans;
        else{
            for(int i = 0; i < m; i++){
                int s = i*n;
                int l = s + n;
                vector<int> subarray(original.begin() + s, original.begin() + l);
                ans.push_back(subarray);
            }

            return ans;
        }
    }
};