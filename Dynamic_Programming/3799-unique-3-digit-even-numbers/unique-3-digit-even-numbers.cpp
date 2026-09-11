class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        int unique_even_numbers = 0;

        for (int i = 100; i < 1000; i += 2) {
            int hundreds = i / 100;
            int tens = (i / 10) % 10;
            int units = i % 10;

            std::vector<int> current_need(10, 0);
            current_need[hundreds]++;
            current_need[tens]++;
            current_need[units]++;

            bool can_form = true;
            for (int d = 0; d < 10; d++) {
                if (current_need[d] > count[d]) {
                    can_form = false;
                    break;
                }
            }

            if (can_form) {
                unique_even_numbers++;
            }
        }

        return unique_even_numbers;
    }
};
