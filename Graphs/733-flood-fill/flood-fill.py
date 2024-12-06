class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        cur = image[sr][sc]
        if cur == color:
            return image

        n = len(image)
        m = len(image[0])
        q = deque()
        q.append((sr, sc))
        image[sr][sc] = color

        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        while q:
            row, col = q.popleft()

            for dr, dc in directions:
                newr = dr + row
                newc = dc + col
                if 0 <= newr < n and 0 <= newc < m and image[newr][newc] == cur:
                    q.append((newr, newc))
                    image[newr][newc] = color
        
        return image