class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> StringNums;

        for (int num : nums)
            StringNums.push_back(to_string(num));

        sort(
            StringNums.begin(), StringNums.end(),
            [](string & a, string & b) { return a + b > b + a; });
        
        if(StringNums[0] == "0") return "0";

        string ans = "";
        for (string s : StringNums)
            ans += s;

        return ans;
    }
};