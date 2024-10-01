class Solution:
    def candy(self, ratings):
        n = len(ratings)
        candy = [1] * n

        # Left to right pass
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candy[i] = candy[i - 1] + 1

        # Right to left pass and summing
        ans = 0
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candy[i] = max(candy[i], candy[i + 1] + 1)
            ans += candy[i]

        # Add the last child's candy
        ans += candy[-1]

        return ans
