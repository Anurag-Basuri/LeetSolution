class Solution {
public:
    int beautySum(string s) {
        int n = s.length(), count = 0;

        for(int i = 0; i < n; i++){
            unordered_map<char, int> checkbox; 
            
            for(int j = i; j < n; j++){
                checkbox[s[j]]++;
                int mx = INT_MIN, mn = INT_MAX;

                for(auto& pair : checkbox){
                   mx = max(mx, pair.second);
                   mn = min(mn, pair.second);   
                }
                count += (mx - mn);
            }
        }

        return count;
    }
};