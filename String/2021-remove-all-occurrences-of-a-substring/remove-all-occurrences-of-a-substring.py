class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        st = ""
        part_size = len(part)

        for ch in s:
            st += ch
            if len(st) >= part_size and st[-part_size:] == part:
                st = st[:-part_size]

        return st
