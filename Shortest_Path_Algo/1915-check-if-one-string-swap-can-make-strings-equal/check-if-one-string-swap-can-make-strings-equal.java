class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if(s1.equals(s2)) return true;
        
        int l1 = s1.length();

        int counter = 0;
        List<Integer> indexes = new ArrayList<>();
        
        for(int i = 0; i < l1; i++){
            if(s1.charAt(i) != s2.charAt(i)){
                counter++;
                indexes.add(i);
            }

            if(counter > 2) return false;
        }
        
        return (indexes.size() == 2) && (s1.charAt(indexes.get(0)) == s2.charAt(indexes.get(1))) && (s1.charAt(indexes.get(1)) == s2.charAt(indexes.get(0)));
    }
}