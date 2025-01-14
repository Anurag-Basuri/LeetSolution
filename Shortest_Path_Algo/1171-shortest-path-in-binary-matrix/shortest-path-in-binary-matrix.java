class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        
         if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }

        int[][] directions = {
            {0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
        };

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0, 0, 1});
        boolean[][] vis = new boolean[n][n];
        vis[0][0] = true;
        
        while(!q.isEmpty()){
            int[] cur = q.poll();
            int row = cur[0];
            int col = cur[1];
            int dist = cur[2];

            if(row == n-1 && col == n-1)
                return dist;
            
            for(int d[]:directions){
                int newRow = row + d[0];
                int newCol = col + d[1];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0 && !vis[newRow][newCol]){
                    vis[newRow][newCol] = true;
                    q.offer(new int[] {newRow, newCol, dist + 1});
                }
            }
        }

        return -1;
    }
}