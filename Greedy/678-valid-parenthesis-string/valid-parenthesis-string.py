class Solution:
    def checkValidString(self, s: str) -> bool:
        min_unmatched = 0
        max_unmatched = 0

        for char in s:
            if char == '(':
                min_unmatched += 1
                max_unmatched += 1
            elif char == ')':
                min_unmatched -= 1
                max_unmatched -= 1
            elif char == '*':
                min_unmatched -= 1
                max_unmatched += 1

            if min_unmatched < 0:
                min_unmatched = 0
            if max_unmatched < 0:
                return False

        return min_unmatched == 0
