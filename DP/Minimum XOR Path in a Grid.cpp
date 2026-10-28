class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = INT_MAX;

        vector<vector<unordered_set<int>>> nums(
            m, vector<unordered_set<int>>(n)
        );

        nums[0][0].insert(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto num : nums[i][j]) {
                    if (j + 1 < n) {
                        nums[i][j + 1].insert(num ^ grid[i][j + 1]);
                    }

                    if (i + 1 < m) {
                        nums[i + 1][j].insert(num ^ grid[i + 1][j]);
                    }
                }
            }
        }

        for (auto num : nums[m - 1][n - 1]) {
            ans = min(ans, num);
        }

        return ans;
    }
};
