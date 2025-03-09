class Solution:
    def maxPower(self, s: str) -> int:
        maxLen = 0
        n = len(s)

        i = 0
        while i < n:
            cur = s[i]  # Current character
            j = i
            length = 0

            # Count consecutive identical characters
            while j < n and s[j] == cur:
                length += 1
                j += 1

            i = j  # Move 'i' to the next non-matching character
            maxLen = max(maxLen, length)

        return maxLen
