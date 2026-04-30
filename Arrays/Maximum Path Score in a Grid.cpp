class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> t(
            m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int cost = k; cost >= 0; cost--) {

                    int newCost = cost + (grid[i][j] > 0);

                    if (newCost > k)
                        continue;

                    if (i == m - 1 && j == n - 1) {
                        t[i][j][cost] = grid[i][j];
                        continue;
                    }

                    int down = -1;
                    int right = -1;

                    if (i + 1 < m)
                        down = t[i + 1][j][newCost];

                    if (j + 1 < n)
                        right = t[i][j + 1][newCost];

                    int bestNext = max(down, right);

                    if (bestNext != -1) {
                        t[i][j][cost] = grid[i][j] + bestNext;
                    }
                }
            }
        }

        return t[0][0][0];
    }
};
