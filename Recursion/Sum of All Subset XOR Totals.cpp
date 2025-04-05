//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    int f(int i, vector<int>& nums, int xr, vector<vector<int>>& dp) {
        if (i >= nums.size()) {
            return xr;
        }

        if (dp[i][xr] != -1) {
            return dp[i][xr];
        }

        int take = f(i + 1, nums, xr ^ nums[i], dp);
        int nottake = f(i + 1, nums, xr, dp);

        return dp[i][xr] = take + nottake;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(33, -1));
        return f(0, nums, 0, dp);
    }
};
