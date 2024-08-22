class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        pn = len(p)
        sn = len(s)
        if pn > sn:
            return []
        
        pcount = {}
        scount = {}
        for i in range(pn):
            pcount[p[i]] = 1 + pcount.get(p[i], 0)
            scount[s[i]] = 1 + scount.get(s[i], 0)

        ans = []
        j = 0
        for i in range(pn, sn):
            if pcount == scount:
                ans.append(j)
            
            scount[s[i]] = 1 + scount.get(s[i], 0)
            scount[s[j]] -= 1

            if scount[s[j]] == 0:
                scount.pop(s[j])
            j += 1
        if pcount == scount:
                ans.append(j)
        
        return ans