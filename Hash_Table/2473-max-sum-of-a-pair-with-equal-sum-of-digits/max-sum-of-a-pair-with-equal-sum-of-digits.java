class Solution {
    public static int sumDigits(int num) {
        return (num == 0) ? 0 : (num % 10 + sumDigits(num / 10));
    }

    public int maximumSum(int[] nums) {
        HashMap<Integer, Integer> store = new HashMap<>();
        int max_sum = -1;

        for(int num:nums){
            int sum = sumDigits(num);

            if(store.containsKey(sum)){
                max_sum = Math.max(max_sum, num + store.get(sum));
                store.put(sum, Math.max(store.get(sum), num));
            }
            else{
                store.put(sum, num);
            }
        }

        return max_sum;
    }
}