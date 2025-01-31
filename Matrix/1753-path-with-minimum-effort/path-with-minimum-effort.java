class Solution {
    public int minimumEffortPath(int[][] heights) {
        int rows = heights.length;
        int cols = heights[0].length;
        
        // Directions for moving in 4 directions (right, down, left, up)
        int[][] directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // Min heap (Priority Queue) to process the least effort path first
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

        // Effort matrix to store the minimum effort required to reach each cell
        int[][] effort = new int[rows][cols];
        for (int[] row : effort) Arrays.fill(row, Integer.MAX_VALUE);
        effort[0][0] = 0;

        pq.offer(new int[]{0, 0, 0}); // {effort, row, col}

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int currEffort = current[0];
            int row = current[1];
            int col = current[2];

            // If we reach the bottom-right cell, return the minimum effort
            if (row == rows - 1 && col == cols - 1) {
                return currEffort;
            }

            // Explore all 4 possible directions
            for (int[] dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int diff = Math.abs(heights[row][col] - heights[newRow][newCol]);
                    int maxEffort = Math.max(currEffort, diff);

                    // If this path offers a smaller effort, update and push it to the queue
                    if (maxEffort < effort[newRow][newCol]) {
                        effort[newRow][newCol] = maxEffort;
                        pq.offer(new int[]{maxEffort, newRow, newCol});
                    }
                }
            }
        }
        return 0; // This line is never reached
    }
}
