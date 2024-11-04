class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1;
        char present = word[0];

        for(int i = 1; i < word.size(); i++){
            if(present == word[i] && count < 9) count++;
            else{
                comp += to_string(count) + present;
                present = word[i];
                count = 1;
            }
        }

        comp += to_string(count) + present;

        return comp;
    }
};