class Solution:
    def backtracking(self, n, open, closed, current, ans):
        if open == n and closed == n:
            ans.append(current)
            return
        
        if open < n:
            self.backtracking(n, open + 1, closed, current + '(', ans)
                  
        if closed < open:
            self.backtracking(n, open, closed + 1, current + ')', ans)

    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        self.backtracking(n, 0, 0, "", ans)
        return ans