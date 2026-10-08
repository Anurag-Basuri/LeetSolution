class Solution {
    public String removeOuterParentheses(String s) {
        int c = 0;
        String result = "";
        
        for (char i : s.toCharArray()) {
            if (c > 0 && i == '(') {
                result += i;
            }
            if (i == '(') {
                c++;
            }
            if (i == ')' && c == 1) {
                c--;
            } else if (i == ')') {
                result += i;
                c--;
            }
        }
        
        return result;
    }
}