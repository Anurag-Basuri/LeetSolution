class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();

        int i = 0;
        for(i = 1; i < n; i++)
            if(s[i - 1] != s[i]) break;
        
        for(i; i < n; i++) {
            if(s[i] == '1') return false;
        }

        return true;
    }
};