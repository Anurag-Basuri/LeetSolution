class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int i = low; i <= high; i++) {
            String s = String.valueOf(i);
            if (s.length() % 2 != 0) continue;

            int mid = s.length() / 2;
            int sum1 = 0, sum2 = 0;

            for (int j = 0; j < mid; j++)
                sum1 += s.charAt(j) - '0';
            for (int j = mid; j < s.length(); j++)
                sum2 += s.charAt(j) - '0';

            if (sum1 == sum2)
                count++;
        }

        return count;
    }
}
