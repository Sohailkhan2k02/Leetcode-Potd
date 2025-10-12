int pows[50][31], C[31][31], dp[51][31][31][31], MOD = 1e9 + 7;
auto init = []() { for (int i = 0; i < 31; ++i) { C[i][0] = C[i][i] = 1; for (int j = 1; j < i; ++j) { C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; } } return 0; }();
class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size(), ret = 0;
        for (int ind = 0; ind <= n; ++ind) for (int i = 0; i <= m; ++i) for (int j = 0; j <= m; ++j) for (int k = 0; k <= m; ++k) dp[ind][i][j][k] = 0;
        for (int i = n - 1; i >= 0; --i) for (int j = pows[i][0] = 1; j <= m; ++j) pows[i][j] = 1LL * pows[i][j - 1] * nums[i] % MOD; dp[0][m][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= m; ++k) {
                    for (int ii = 0; ii <= m; ++ii) {
                        for (int jj = 0; jj <= j && dp[i][j][k][ii]; ++jj) {
                            (dp[i + 1][j - jj][k + jj >> 1][ii + (k + jj & 1)] += dp[i][j][k][ii] * 1LL * pows[i][jj] % MOD * C[j][jj] % MOD) %= MOD;
                        }
                    }
                }
            }
        }
        for (int i = 0; i <= m; ++i) if (int x = __builtin_popcount(i); x <= k) ret = (ret + dp[n][0][i][k - x]) % MOD;
        return ret;
    }
};
