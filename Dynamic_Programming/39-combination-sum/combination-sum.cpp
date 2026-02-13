class Solution {
public:
    void backTrack(int i, vector<int> &can, vector<vector<int>> &ans, vector<int> &cur, int tar){
        if(i < 0) return;

        if(tar == 0) {
            ans.push_back(cur);
            return;
        }

        if(tar >= can[i]) {
            cur.push_back(can[i]);
            backTrack(i, can, ans, cur, tar - can[i]);
            cur.pop_back();
        }
    
        backTrack(i - 1, can, ans, cur, tar);

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int> cur;

        backTrack(can.size() - 1, can, ans, cur, target);
        return ans;
    }
};