class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        // dp[i][j][r] = number of paths from (0,0) to (i,j) with sum % k = r
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, 0))
        );

        dp[0][0][ grid[0][0] % k ] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                // already initialized (0,0), so for others we accumulate from top/left
                for (int r = 0; r < k; ++r) {
                    if (i == 0 && j == 0) continue; // base handled

                    long long ways = 0;

                    // from top
                    if (i > 0) {
                        ways += dp[i-1][j][r];
                    }
                    // from left
                    if (j > 0) {
                        ways += dp[i][j-1][r];
                    }

                    if (ways == 0) continue; // no paths with remainder r reaching here

                    // Now add current cell and compute new remainder
                    int newRem = (r + grid[i][j]) % k;
                    dp[i][j][newRem] = (dp[i][j][newRem] + ways) % MOD;
                }
            }
        }

        // We want total paths whose sum % k == 0 at bottom-right
        return dp[m-1][n-1][0];
    }
};
