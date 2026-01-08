class Solution:
    def calculateScore(self, s: str) -> int:
        total = 0
        n = len(s)
        stMap = {}

        for i in range(n):
            ch = s[i]
            chMir = chr(ord('z') - ord(ch) + ord('a'))

            if chMir in stMap and stMap[chMir]:
                total += i - stMap[chMir][-1]
                stMap[chMir].pop()
            else:
                if ch not in stMap:
                    stMap[ch] = []
                stMap[ch].append(i)

        return total
