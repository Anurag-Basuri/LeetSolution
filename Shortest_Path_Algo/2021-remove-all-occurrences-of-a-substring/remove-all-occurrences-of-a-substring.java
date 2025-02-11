class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder st = new StringBuilder();
        int partSize = part.length();

        for (char ch : s.toCharArray()) {
            st.append(ch);
            if (st.length() >= partSize && st.substring(st.length() - partSize).equals(part)) {
                st.delete(st.length() - partSize, st.length());
            }
        }

        return st.toString();
    }
}
