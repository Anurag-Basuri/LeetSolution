class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        maxl = 0 
        ans = 0  
        l = 0   
        count = {}
        for r in range(n):  
            count[s[r]] = count.get(s[r], 0) + 1
            maxl = max(maxl, count[s[r]])  
            
            if (r - l + 1) - maxl > k:
                count[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)

        return ans
