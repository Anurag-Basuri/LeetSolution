class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        char cur = s[0];
        int total = 0;

        for(int i = 0; i < s.size(); i++){
            if(cur == s[i]) count++;
            else{
                if(count % 2 != 0){
                    total++;
                    count = 0;
                }
                else count = 1;
                cur = s[i];
            }
        }

        return total;
    }
};