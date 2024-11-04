class Solution {
    public String compressedString(String word) {
        StringBuilder comp = new StringBuilder();
        int count = 1;
        char present = word.charAt(0);
        
        for (int i = 1; i < word.length(); i++) {
            if (present == word.charAt(i) && count < 9) {
                count++;
            } else {
                comp.append(count).append(present);
                present = word.charAt(i);
                count = 1;
            }
        }
        
        comp.append(count).append(present);
        
        return comp.toString();
    }
}