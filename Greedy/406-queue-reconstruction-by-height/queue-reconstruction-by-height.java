class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (a, b) -> {
            return (a[0] == b[0])? a[1] - b[1] : b[0] - a[0];
        });

        List<int[]> result = new ArrayList<>();

        for(int[] person:people){
            result.add(person[1], person);
        }

        return result.toArray(new int[people.length][]);
    }
}