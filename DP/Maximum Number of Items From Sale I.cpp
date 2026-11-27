
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> dp(budget + 1, 0);
        int mn = INT_MAX;

        for (auto& item : items) {
            mn = min(mn, item[1]);
        }

        for (int i = 0; i < n; i++) {
            int fact = items[i][0];
            int pri = items[i][1];

            int free = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % fact == 0) {
                    free++;
                }
            }

            int val = free + 1;

            for (int j = budget; j >= pri; j--) {
                dp[j] = max(dp[j], dp[j - pri] + val);
            }
        }

        int ans = 0;

        for (int i = 0; i <= budget; i++) {
            int total = dp[i] + (budget - i) / mn;
            ans = max(ans, total);
        }

        return ans;
    }
};
