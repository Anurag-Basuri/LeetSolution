class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        vis = [[0] * m for _ in range(n)]
        q = deque()
        fresh_count = 0

        # Initialize the visited array and queue
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    vis[i][j] = 2
                    q.append(((i, j), 0))  # Push rotten orange with time 0
                elif grid[i][j] == 1:
                    fresh_count += 1

        # Define the directions for 4-way movement
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

        time = 0
        rotted_count = 0

        # Process the queue
        while q:
            (row, col), t = q.popleft()
            time = max(time, t)  # Track the maximum time

            # Traverse in 4 directions
            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc
                if 0 <= new_row < n and 0 <= new_col < m and grid[new_row][new_col] == 1 and vis[new_row][new_col] == 0:
                    q.append(((new_row, new_col), t + 1))
                    vis[new_row][new_col] = 2  # Mark as visited (rotted)
                    rotted_count += 1  # Increment the count of rotted oranges

        # Check if all fresh oranges were rotted
        if rotted_count != fresh_count:
            return -1

        return time
