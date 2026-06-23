class Solution {
public:
    int maxScore(vector<int>& cardsPoints, int k) {
        int n = cardsPoints.size();
        int sum = 0;
        int ksum = 0;

        for(int i = 0; i < n; i++) {
            sum += cardsPoints[i];

            if(i + 1 + k == n) ksum = sum;
        }

        int ans = sum - ksum;
        cout << ksum << " " << sum << " " << ans;

        for(int i = 0; i < k; i++) {
            ksum = ksum - cardsPoints[i] + cardsPoints[n - k + i];
            ans = max(ans, sum - ksum);
        }

        return ans;
    }
};