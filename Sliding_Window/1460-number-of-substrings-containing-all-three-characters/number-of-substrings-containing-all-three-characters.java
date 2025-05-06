public class Solution {
    public int numberOfSubstrings(String s) {
        int[] lastseen = new int[3];
        Arrays.fill(lastseen, -1);
        int ans = 0;
        
        for (int i = 0; i < s.length(); i++) {
            lastseen[s.charAt(i) - 'a'] = i;

            ans += 1 + Math.min(lastseen[0], Math.min(lastseen[1], lastseen[2]));
        }
        return ans;
    }
}