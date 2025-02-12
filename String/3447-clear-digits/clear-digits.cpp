class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(isdigit(s[i]) && !st.empty())
                st.pop();
            else
                st.push(s[i]);
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};