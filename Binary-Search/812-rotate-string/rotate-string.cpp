class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        if(n == goal.length()){
            for(int i = 0; i < n; i++)
                if((s+s).substr(i, n) == goal) return true;
        }
        else return false;

        return false;
    }
};