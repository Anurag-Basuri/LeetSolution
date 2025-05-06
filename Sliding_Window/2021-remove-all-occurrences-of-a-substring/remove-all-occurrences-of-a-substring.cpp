class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st = "";
        int partSize = part.size();

        for(char ch:s){
            st += ch;

            if(st.size() >= partSize && st.substr(st.size() - partSize) == part)
                st.erase(st.size() - partSize);
        }

        return st;
    }
};