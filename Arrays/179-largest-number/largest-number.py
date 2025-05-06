class Solution:
    def largestNumber(self, nums):
        # Convert all integers to strings
        str_nums = list(map(str, nums))

        # Custom comparator
        def compare(a, b):
            return (int(b + a) - int(a + b))

        # Sort using custom comparator
        str_nums.sort(key=cmp_to_key(compare))

        # If the first number is "0", the result is "0"
        if str_nums[0] == "0":
            return "0"

        # Join the sorted strings
        return ''.join(str_nums)