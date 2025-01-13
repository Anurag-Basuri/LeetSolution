class Solution:
    def shortestPathBinaryMatrix(self, grid):
        n = len(grid)
        
        # Check if start or end cell is blocked
        if grid[0][0] != 0 or grid[n - 1][n - 1] != 0:
            return -1

        # Directions for 8 possible moves
        directions = [
            (0, -1), (0, 1), (1, 0), (-1, 0), 
            (-1, -1), (1, 1), (-1, 1), (1, -1)
        ]

        # BFS queue: (row, col, distance)
        q = deque([(0, 0, 1)])

        # Visited array
        vis = [[False] * n for _ in range(n)]
        vis[0][0] = True

        while q:
            row, col, dist = q.popleft()

            # If we reach the bottom-right cell, return the distance
            if row == n - 1 and col == n - 1:
                return dist

            # Explore all 8 directions
            for dr, dc in directions:
                newRow, newCol = row + dr, col + dc

                # Check if the new cell is valid and unvisited
                if 0 <= newRow < n and 0 <= newCol < n and grid[newRow][newCol] == 0 and not vis[newRow][newCol]:
                    vis[newRow][newCol] = True  # Mark as visited
                    q.append((newRow, newCol, dist + 1))

        # If no path is found, return -1
        return -1
