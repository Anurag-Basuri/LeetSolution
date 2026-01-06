class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0 || k%5 == 0) return -1;

        unordered_set<int> reminders;
        int reminder = 1, count = 1;

        while(reminder%k != 0) {
            int n = reminder * 10 + 1;
            reminder = n % k;
            count++;

            if(reminders.find(reminder) != reminders.end()) return -1;
            else reminders.insert(reminder);
        }

        return count;
    }
};