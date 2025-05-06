class Solution {
public:
    int maxPower(string s) {
        int maxLen = 0;
        int n = s.size();

        for(int i = 0; i < n; ){
            char cur = s[i];
            int j = i, len = 0;

            while(j < n && s[j] == cur){
                len++;
                j++;
            }
            cout << len;
            i = j;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};