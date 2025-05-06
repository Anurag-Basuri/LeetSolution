class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False

        from collections import Counter

        freq1 = Counter(word1)
        freq2 = Counter(word2)

        # Check if both words use the same set of characters
        if set(freq1.keys()) != set(freq2.keys()):
            return False

        # Check if frequency distributions match (ignoring characters)
        return sorted(freq1.values()) == sorted(freq2.values())
