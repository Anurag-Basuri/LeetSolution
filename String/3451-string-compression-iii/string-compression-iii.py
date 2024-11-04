class Solution:
    def compressedString(self, word: str) -> str:
        comp = ""
        count = 1
        present = word[0]
        
        for i in range(1, len(word)):
            if present == word[i] and count < 9:
                count += 1
            else:
                comp += str(count) + present
                present = word[i]
                count = 1
                
        comp += str(count) + present
        
        return comp