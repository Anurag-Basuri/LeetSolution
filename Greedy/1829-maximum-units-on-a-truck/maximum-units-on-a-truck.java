class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a, b) -> b[1] - a[1]);

        int totalUnits = 0;
        int size = 0;

        for (int i = 0; i < boxTypes.length && size < truckSize; i++) {
            if (size + boxTypes[i][0] > truckSize) {
                totalUnits += boxTypes[i][1] * (truckSize - size);
                break;
            } else {
                totalUnits += boxTypes[i][0] * boxTypes[i][1];
                size += boxTypes[i][0];
            }
        }

        return totalUnits;
    }
}
