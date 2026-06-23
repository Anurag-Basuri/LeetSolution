class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> substrings;

        for (int i = 0; i + k <= s.size(); ++i){
            string subs = s.substr(i, k);
            substrings.insert(subs);
        }

        return substrings.size() == pow(2, k);
    }
};