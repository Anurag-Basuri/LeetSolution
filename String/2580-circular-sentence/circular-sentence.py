class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        new = sentence.split()
        toggle = False
        l = len(new)

        for i in range(l - 1):
            if new[i][-1] != new[i+1][0]:
                return False
        
        if new[-1][-1] != new[0][0]:
            return  False

        return True