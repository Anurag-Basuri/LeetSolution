class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        st = set()

        for i in nums:
            if i in st:
                return i
            st.add(i)

        return -1
