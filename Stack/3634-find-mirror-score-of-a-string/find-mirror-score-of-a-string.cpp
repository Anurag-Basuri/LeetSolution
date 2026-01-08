class Solution {
public:
    long long calculateScore(string s) {
        long long sum = 0;
        int n = s.size();
        unordered_map<char, stack<int>> stMap;

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            char chMir = 'z' - ch + 'a';

            if(!stMap[chMir].empty()) {
                sum += i - stMap[chMir].top();
                stMap[chMir].pop();
            } else
                stMap[ch].push(i);
        }

        return sum;
    }
};