class Solution {
public:
    string processStr(string s) {
        string str = "";

        for (char ch : s) {
            if (ch == '#')
                str = str + str;
             else if (ch == '*') {
                if (!str.empty())
                    str.pop_back();
            } else if (ch == '%')
                reverse(str.begin(), str.end());
            else
                str = str + ch;
        }

        return str;
    }
};