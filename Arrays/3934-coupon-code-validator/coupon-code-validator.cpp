class Solution {
public:
    bool check(string s) {
        static const regex re("^[a-zA-Z0-9_]+$");

        return regex_match(s, re);
    }
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<vector<string>> temp;

        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i])
                continue;

            if (businessLine[i] != "grocery" &&
                businessLine[i] != "electronics" &&
                businessLine[i] != "pharmacy" &&
                businessLine[i] != "restaurant")
                continue;

            if (check(code[i]))
                temp.push_back({businessLine[i], code[i]});
        }

        sort(temp.begin(), temp.end(),
             [](const vector<string>& a, const vector<string>& b) {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 else
                     return a[0] < b[0];
             });

        vector<string> ans;

        for (auto i : temp) {
            ans.push_back(i[1]);
        }

        return ans;
    }
};