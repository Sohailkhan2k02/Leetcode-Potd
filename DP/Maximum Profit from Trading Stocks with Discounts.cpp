class Solution {
public:
    vector<vector<int>> tree;
    vector<int> buyPrice, sellPrice;
    int budget;

    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int B) {
        buyPrice = present;
        sellPrice = future;
        budget = B;

        tree.assign(n, {});
        for (auto &h : hierarchy) {
            tree[h[0] - 1].push_back(h[1] - 1);
        }

        auto dp = dfs(0);
        return dp[budget][0];
    }

    vector<vector<int>> dfs(int u) {
        vector<vector<int>> dp(budget + 1, vector<int>(2, 0));

        for (int v : tree[u]) {
            auto child = dfs(v);
            vector<vector<int>> next(budget + 1, vector<int>(2, 0));

            for (int b = 0; b <= budget; b++) {
                for (int cb = 0; cb <= b; cb++) {
                    next[b][0] = max(next[b][0], dp[b - cb][0] + child[cb][0]);
                    next[b][1] = max(next[b][1], dp[b - cb][1] + child[cb][1]);
                }
            }
            dp.swap(next);
        }

        vector<vector<int>> ans(budget + 1, vector<int>(2, 0));
        int discounted = buyPrice[u] / 2;

        for (int b = 0; b <= budget; b++) {
            ans[b][0] = dp[b][0];
            if (b >= buyPrice[u])
                ans[b][0] = max(ans[b][0],
                                sellPrice[u] - buyPrice[u] + dp[b - buyPrice[u]][1]);

            ans[b][1] = dp[b][0];
            if (b >= discounted)
                ans[b][1] = max(ans[b][1],
                                sellPrice[u] - discounted + dp[b - discounted][1]);
        }
        return ans;
    }
};
