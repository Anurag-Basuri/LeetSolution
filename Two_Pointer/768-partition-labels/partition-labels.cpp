class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> indices;
        vector<int> ans;
        int n = s.length();

        for(int i = 0; i < n; i++)
            indices[s[i]] = i;
        
        int i = 0;
        while(i < n){
            int x = indices[s[i]];

            for(int j = i; j <= x; j++){
                if(x < indices[s[j]])
                    x = indices[s[j]];
            }

            ans.push_back(x - i + 1);
            i = x + 1;
        }

        return ans;
    }
};