class Solution:
    def updateMatrix(self, mat):
        n = len(mat)
        m = len(mat[0])
        
        # Initialize distance matrix and visited matrix
        dist = [[0] * m for _ in range(n)]
        vis = [[0] * m for _ in range(n)]
        q = deque()
        
        # Push all 0s into the queue and mark them as visited
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    q.append(((i, j), 0))
                    vis[i][j] = 1
        
        # Direction vectors for moving up, left, down, right
        drow = [-1, 0, 1, 0]
        dcol = [0, -1, 0, 1]
        
        # Perform BFS
        while q:
            (row, col), steps = q.popleft()
            dist[row][col] = steps
            
            for i in range(4):
                nrow = row + drow[i]
                ncol = col + dcol[i]
                
                # If the neighbor is valid and not visited
                if 0 <= nrow < n and 0 <= ncol < m and not vis[nrow][ncol]:
                    vis[nrow][ncol] = 1
                    q.append(((nrow, ncol), steps + 1))
        
        return dist
