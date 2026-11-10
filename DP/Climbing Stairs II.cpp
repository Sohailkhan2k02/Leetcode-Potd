class Solution {
public:

    int solve(vector<int>& costs, int n, int i, vector<int>& dp) {

        if (i == n - 1) {
            return costs[i];
        }

        if (i >= n) {
            return INT_MAX / 2;
        }

        if (dp[i + 1] != -1) {
            return dp[i + 1];
        }

        int a = 1 + solve(costs, n, i + 1, dp);
        int b = 4 + solve(costs, n, i + 2, dp);
        int c = 9 + solve(costs, n, i + 3, dp);

        if (i != -1) {
            return dp[i + 1] = costs[i] + min(a, min(b, c));
        }

        return dp[i + 1] = min(a, min(b, c));
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return solve(costs, n, -1, dp);
    }
};
