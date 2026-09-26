class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        int flag = 0;
        string ans = "";
        unordered_map<string, string> find;
        string a = "";

        for(auto& x:k)
            find[x[0]] = x[1];

        for(char ch:s) {
            if(flag) {
                if(ch == ')'){
                    ans += (find.find(a) != find.end())? find[a]:"?";
                    flag = 0;
                    a = "";
                    continue;
                }

                a += ch;
                continue;
            }

            if(ch == '(') {
                flag = 1;
                continue;
            }

            ans += ch;
        }

        return ans;
    }
};