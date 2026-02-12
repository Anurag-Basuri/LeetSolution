class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> store;
            int maxFreq = 0;

            for (int j = i; j < n; j++) {
                store[s[j]]++;
                maxFreq = max(maxFreq, store[s[j]]);

                int len = j - i + 1;

                if (len == maxFreq * store.size())
                    max_len = max(max_len, len);
            }
        }

        return max_len;
    }
};