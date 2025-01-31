class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        rows, cols = len(heights), len(heights[0])
        directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        
        pq = [(0, 0, 0)]  # (effort, row, col)
        effort = [[float('inf')] * cols for _ in range(rows)]
        effort[0][0] = 0
        
        while pq:
            curr_effort, row, col = heapq.heappop(pq)
            
            if row == rows - 1 and col == cols - 1:
                return curr_effort
            
            for dr, dc in directions:
                new_row, new_col = row + dr, col + dc
                
                if 0 <= new_row < rows and 0 <= new_col < cols:
                    diff = abs(heights[row][col] - heights[new_row][new_col])
                    max_effort = max(curr_effort, diff)
                    
                    if max_effort < effort[new_row][new_col]:
                        effort[new_row][new_col] = max_effort
                        heapq.heappush(pq, (max_effort, new_row, new_col))
        
        return 0
