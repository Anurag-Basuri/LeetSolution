class Solution {
public:
    bool areOccurrencesEqual(string s) { 
        unordered_map<char, int> map;

        for(auto i:s)
            map[i]++;
        
        int count = map[s[0]];
        for(auto it = map.begin(); it != map.end(); it++)
            if(it->second != count) return false;
        
        return true;
    }
};