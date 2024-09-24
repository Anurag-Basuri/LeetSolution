class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int lg = g.size(), ls = s.size();
        int l = 0, r = 0, count = 0;

        while(l < lg && r < ls){
            if(g[l] <= s[r]){
                l++;
                r++;
                count++;
            }
            else r++;
        }

        return count;
    }
};