class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));

        int totalFreeDays = 0;
        int lastEnd = 0;

        for (int[] meeting : meetings) {
            if (meeting[0] > lastEnd) {
                totalFreeDays += meeting[0] - lastEnd - 1;
            }
            lastEnd = Math.max(lastEnd, meeting[1]);
        }

        totalFreeDays += days - lastEnd;
        return totalFreeDays;
    }
}