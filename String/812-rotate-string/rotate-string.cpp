class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        if (s == goal) {
            return true;
        }
        
        int l = s.length();
        while (l > 0) {
            s = s.substr(1) + s[0];
            if (s == goal) {
                return true;
            }
            l--;
        }
        
        return false;
    }
};
