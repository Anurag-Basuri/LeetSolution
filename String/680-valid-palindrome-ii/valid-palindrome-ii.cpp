class Solution {
public:
    bool isPalindrome(string s){
        int l = 0, r = s.length() - 1;

        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1, flag = 0;

        while(l <= r){
            if(s[l] != s[r]){
                return isPalindrome(s.substr(l, r-l)) || isPalindrome(s.substr(l+1, r-l));
            }
            l++;
            r--;
        }

        return true;
    }
};