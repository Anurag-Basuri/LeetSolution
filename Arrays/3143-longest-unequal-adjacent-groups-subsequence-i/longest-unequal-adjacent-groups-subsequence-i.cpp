class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ans;
        int toggle = groups[0];
        ans.push_back(words[0]);

        for(int i = 1; i <  n; i++) {
            if(toggle != groups[i]) {
                toggle = groups[i];
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};