class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        const long long NEG = -1e18;
        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG));
        dp[0][0] = 0;  
        for (int price : prices) {
            vector<vector<long long>> newdp = dp;
            for (int t = 0; t <= k; t++) {
                if (dp[t][0] != NEG)
                    newdp[t][1] = max(newdp[t][1], dp[t][0] - price);
                if (dp[t][0] != NEG)
                    newdp[t][2] = max(newdp[t][2], dp[t][0] + price);
                if (t < k) {
                    if (dp[t][1] != NEG)
                        newdp[t + 1][0] = max(newdp[t + 1][0], dp[t][1] + price);
                    if (dp[t][2] != NEG)
                        newdp[t + 1][0] = max(newdp[t + 1][0], dp[t][2] - price);
                }
            }
            dp = newdp;
        }

        long long ans = 0;
        for (int t = 0; t <= k; t++)
            ans = max(ans, dp[t][0]);

        return ans;
    }
};
