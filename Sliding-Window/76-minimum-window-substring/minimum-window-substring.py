class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n, m = len(s), len(t)
        min_len, count = float('inf'), 0
        l, r, sInd = 0, 0, -1
        seen = defaultdict(int)

        for c in t:
            seen[c] += 1

        while r < n:
            if seen[s[r]] > 0:
                count += 1
            seen[s[r]] -= 1

            while count == m:
                if r - l + 1 < min_len:
                    min_len = r - l + 1
                    sInd = l

                seen[s[l]] += 1
                if seen[s[l]] > 0:
                    count -= 1
                l += 1
            r += 1

        return "" if sInd == -1 else s[sInd:sInd + min_len]