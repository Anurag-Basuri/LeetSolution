class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream stream(sentence);
        vector<string> words;
        string word;
        
        while (stream >> word) {
            words.push_back(word);
        }
        
        int n = words.size();
        
        for (int i = 0; i < n - 1; i++) {
            if (words[i].back() != words[i + 1].front()) {
                return false;
            }
        }
        
        if (words[n - 1].back() != words[0].front()) {
            return false;
        }
        
        return true;
    }
};