class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        int n = derived.size();
        for(int i = 0; i < n; i++)
            ans ^= derived[i];
        
        if(ans == 0) return true;
        else return false;
    }
};