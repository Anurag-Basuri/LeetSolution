class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0, n = s.size();
        string st = "";

        for (int i = 0; i < n; i++) {
            // Odd length palindrome (single center character)
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > ans) {
                    ans = len;
                    st = s.substr(l, len);
                }
                l--; // Expand left
                r++; // Expand right
            }

            // Even length palindrome (two center characters)
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len > ans) {
                    ans = len;
                    st = s.substr(l, len);
                }
                l--; // Expand left
                r++; // Expand right
            }
        }

        return st;
    }
};
