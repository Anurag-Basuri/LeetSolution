class Solution:
    def minChanges(self, s: str) -> int:
        count = 0
        cur = s[0]
        total = 0

        for i in range(len(s)):
            if cur == s[i]:
                count += 1
            else:
                if count % 2 != 0:
                    total += 1
                    count = 0
                else:
                    count = 1
                cur = s[i]

        if count % 2 != 0:
            total += 1

        return total
