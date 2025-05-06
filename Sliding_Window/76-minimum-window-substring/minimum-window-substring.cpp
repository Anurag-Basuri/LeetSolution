class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int minl = INT_MAX, count = 0;
        int l = 0, r = 0, sInd = -1;
        unordered_map<char, int> seen;

        for(auto& a:t) seen[a]++;

        while(r < n){
            if(seen[s[r]] > 0) count++;
            seen[s[r]]--;

            while(count == m){
                if(r-l+1 < minl){
                    minl = r-l+1;
                    sInd = l;
                }

                seen[s[l]]++;
                if(seen[s[l]] > 0) count--;
                l++;
            }
            r++;
        }

        return (sInd == -1)? "" : s.substr(sInd, minl);
    }
};
