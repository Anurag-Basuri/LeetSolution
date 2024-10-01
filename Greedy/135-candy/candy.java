class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int ans = 0;
        int[] candy = new int[n];

        // Initialize each child with 1 candy
        for (int i = 0; i < n; i++) {
            candy[i] = 1;
        }

        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        // Right to left pass and summing
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = Math.max(candy[i], candy[i + 1] + 1);
            }
            ans += candy[i];
        }

        // Add the last child's candy
        ans += candy[n - 1];

        return ans;
    }
}
