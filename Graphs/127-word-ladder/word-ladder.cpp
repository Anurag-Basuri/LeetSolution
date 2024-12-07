class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Create a set for fast lookup of words
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // If the endWord is not in the wordList, we cannot form a transformation
        if (st.find(endWord) == st.end()) return 0;

        // BFS queue: stores {current word, transformation steps}
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord); // Remove the starting word to avoid revisiting it

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // Try all possible transformations
            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i]; // Save the original character

                // Replace with every possible character from 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // Check if the transformed word is the endWord
                    if (word == endWord) return steps + 1;

                    // If the transformed word exists in the set, process it
                    if (st.find(word) != st.end()) {
                        st.erase(word); // Remove the word from the set
                        q.push({word, steps + 1});
                    }
                }

                word[i] = originalChar; // Restore the original character
            }
        }

        return 0; // If no transformation sequence is found
    }
};
