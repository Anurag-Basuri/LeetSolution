class Solution {
public:
    // Function to calculate the sum of digits
    int sumDigits(int num) {
        return (num == 0) ? 0 : (num % 10 + sumDigits(num / 10));
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> store; // To store the largest number for each digit sum
        int max_sum = -1;

        for (int num : nums) {
            int sum = sumDigits(num); // Get the sum of digits

            if (store.find(sum) != store.end()) {
                // If there's already a number with the same sum of digits
                max_sum = max(max_sum, num + store[sum]);
                // Update the largest number for that sum
                store[sum] = max(store[sum], num);
            } else {
                // If no number with that sum of digits, add it to the map
                store[sum] = num;
            }
        }

        return max_sum;
    }
};