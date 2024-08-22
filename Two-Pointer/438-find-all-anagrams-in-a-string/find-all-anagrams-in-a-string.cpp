class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pn = p.length();
        int sn = s.length();
        
        if (pn > sn) {
            return {};
        }
        
        unordered_map<char, int> pcount, scount;
        for (int i = 0; i < pn; ++i) {
            pcount[p[i]]++;
            scount[s[i]]++;
        }

        vector<int> ans;
        int j = 0;
        
        for (int i = pn; i < sn; ++i) {
            if (pcount == scount) {
                ans.push_back(j);
            }
            
            scount[s[i]]++;
            scount[s[j]]--;
            
            if (scount[s[j]] == 0) {
                scount.erase(s[j]);
            }
            j++;
        }
        
        if (pcount == scount) {
            ans.push_back(j);
        }
        
        return ans;
    }
};