class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> vis;

            for (int j = i; j < n; j++) {
                if (vis.find(s[j]) != vis.end())
                    break;
                else {
                    vis.insert(s[j]);
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        return max_len;
    }
};
