class Solution {
public:
    int maxProfit(vector<int>& p, vector<int>& st, int k) {
        int n = p.size();

        vector<long long> profit_sum(n, 0);
        vector<long long> new_p_sum(n, 0);

        profit_sum[0] = 1LL * st[0] * p[0];
        new_p_sum[0] = p[0];

        for (int i = 1; i < n; i++) {
            profit_sum[i] = profit_sum[i - 1] + 1LL * p[i] * st[i];
            new_p_sum[i] = new_p_sum[i - 1] + p[i];
        }

        long long res = profit_sum[n - 1];

        for (int i = k - 1; i < n; i++) {
            long long left = (i - k < 0) ? 0 : profit_sum[i - k];
            long long right = profit_sum[n - 1] - profit_sum[i];
            long long change_window =
                new_p_sum[i] - ((i - k >= 0) ? new_p_sum[i - k] : 0);

            res = max(res, left + change_window + right);
        }

        return (int)res;
    }
};
