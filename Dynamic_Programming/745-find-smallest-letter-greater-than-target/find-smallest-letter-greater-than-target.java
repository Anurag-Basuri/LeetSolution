class Solution {
    public char nextGreatestLetter(char[] let, char tar) {
        for(char i:let)
        {
            if(i>tar)
                return i;
        }
        return let[0];
    }
}