class Solution:
    def numberOfAlternatingGroups(self, colors: list[int], k: int) -> int:
        n = len(colors)
        count = 0
        curLen = 1
        prevColor = colors[0]

        # Loop through the array with circular traversal logic
        for i in range(1, n + k - 1):
            idx = i % n  # Circular index calculation

            # If the current color matches the previous one
            if colors[idx] == prevColor:
                curLen = 1  # Reset the alternating sequence length
                prevColor = colors[idx]  # Update the previous color
                continue

            # Extend the alternating sequence
            curLen += 1

            # If alternating sequence reaches at least k, count it
            if curLen >= k:
                count += 1

            # Update previous color for the next iteration
            prevColor = colors[idx]

        return count
