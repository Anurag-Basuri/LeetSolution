class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for(int num:nums) pq.offer((long) num);
        int count = 0;

        while(pq.size() > 1 && pq.peek() < k){
            long a = pq.poll();
            long b = pq.poll();

            pq.offer(a*2 + b);
            count++;
        }

        return count;
    }
}