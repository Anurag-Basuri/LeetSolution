class Solution:
    def firstCompleteIndex(self, arr, mat):
        m = len(mat)
        n = len(mat[0])
        
        indices = {}
        for i in range(m):
            for j in range(n):
                indices[mat[i][j]] = (i, j)

        l = len(arr)
        row = [0] * m
        col = [0] * n

        for i in range(l):
            x, y = indices[arr[i]]
            row[x] += 1
            col[y] += 1

            if row[x] == n or col[y] == m:
                return i

        return -1
