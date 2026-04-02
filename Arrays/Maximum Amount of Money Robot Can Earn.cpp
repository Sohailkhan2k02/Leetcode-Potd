class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        // dp[i][j][k] = max coins reaching (i,j) using k neutralizations
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        // Base case for (0,0)
        for (int k = 0; k <= 2; ++k) {
            if (coins[0][0] >= 0) dp[0][0][k] = coins[0][0];
            else dp[0][0][k] = (k > 0 ? 0 : coins[0][0]);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                for (int k = 0; k <= 2; ++k) {
                    int best_prev = INT_MIN;
                    if (i > 0) best_prev = max(best_prev, dp[i-1][j][k]);
                    if (j > 0) best_prev = max(best_prev, dp[i][j-1][k]);

                    int val = coins[i][j];

                    if (val >= 0) {
                        dp[i][j][k] = best_prev + val;
                    } else {
                        // Option 1: do not neutralize
                        int no_neutral = best_prev + val;

                        // Option 2: use neutralization if available
                        int use_neutral = INT_MIN;
                        if (k > 0) {
                            int best_prev2 = INT_MIN;
                            if (i > 0) best_prev2 = max(best_prev2, dp[i-1][j][k-1]);
                            if (j > 0) best_prev2 = max(best_prev2, dp[i][j-1][k-1]);
                            use_neutral = best_prev2 + 0;
                        }
                        dp[i][j][k] = max(no_neutral, use_neutral);
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};
