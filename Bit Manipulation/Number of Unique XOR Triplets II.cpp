class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAX_XOR = 2048;

        vector<bool> present(MAX_XOR, false);
        for (int x : nums) {
            present[x] = true;
        }

        vector<bool> dp(MAX_XOR, false);
        dp[0] = true;

        for (int step = 0; step < 3; step++) {
            vector<bool> next(MAX_XOR, false);

            for (int cur = 0; cur < MAX_XOR; cur++) {
                if (!dp[cur]) continue;

                for (int v = 0; v < MAX_XOR; v++) {
                    if (present[v]) {
                        next[cur ^ v] = true;
                    }
                }
            }

            dp = move(next);
        }

        int ans = 0;
        for (bool ok : dp) {
            if (ok) ans++;
        }

        return ans;
    }
};
