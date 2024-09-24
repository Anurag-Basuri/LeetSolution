class Solution {
public:
    bool checkValidString(string s) {
        int min = 0, max = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                min++;
                max++;
            } 

            if(s[i] == ')'){
                max--;
                min--;
            }

            if(s[i] == '*'){
                min--;
                max++;
            }

            if(min < 0) min = 0;
            if(max < 0) return false;
        }

        if(min == 0) return true;
        else return false;
    }
};
