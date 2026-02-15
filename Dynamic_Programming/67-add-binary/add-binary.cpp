class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();

        char carry = '0';
        string ans = "";
        int max_len = max(n, m);

        for(int i = 0; i < max_len; i++) {
            char bitA = (i < n) ? a[n - 1 - i] : '0';
            char bitB = (i < m) ? b[m - 1 - i] : '0';

            if (bitA == '1' && bitB == '1') {
                ans += (carry == '1') ? '1' : '0';
                carry = '1';
            }
            else if (bitA == '1' || bitB == '1') {
                ans += (carry == '1') ? '0' : '1';
                carry = (carry == '1') ? '1' : '0';
            }
            else {
                ans += (carry == '1') ? '1' : '0';
                carry = '0';
            }
        }

        if(carry == '1')
            ans += '1';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
