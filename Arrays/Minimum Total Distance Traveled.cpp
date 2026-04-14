class Solution {
public:
    #define ll long long
    vector<vector<ll>> dp;

    ll solve(int i, int j, vector<int>& robots, vector<int>& nums) {
        if (i >= robots.size()) return 0;
        if (j >= nums.size()) return 1e18;

        if (dp[i][j] != -1) return dp[i][j];

        ll take = abs(robots[i] - nums[j]) + solve(i + 1, j + 1, robots, nums);
        ll notake = solve(i, j + 1, robots, nums);

        return dp[i][j] = min(take, notake);
    }

    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        vector<int> nums;

        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());

        for (auto& f : factories) {
            for (int i = 0; i < f[1]; i++) {
                nums.push_back(f[0]);
            }
        }

        dp.assign(robots.size() + 1, vector<ll>(nums.size() + 1, -1));
        return solve(0, 0, robots, nums);
    }
};
