class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastseen(3, -1);
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            lastseen[s[i] - 'a'] = i;

            ans += 1 + *min_element(lastseen.begin(), lastseen.end());
        }

        return ans;
    }
};