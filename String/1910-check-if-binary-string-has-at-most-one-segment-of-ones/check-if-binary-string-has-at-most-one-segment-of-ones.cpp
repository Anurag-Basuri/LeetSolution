class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int c = 0, t = 1;

        for(int i = 1; i < n; i++) {
            if(s[i] == '1') t = 1;
            else if(t == 1) {
                t = 0;
                c++;
            }
        }

        if(t == 1) c++;

        return c <= 1;
    }
};