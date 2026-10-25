class Solution {
public:
    int m, n;
    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r >= m || r < 0 || c >= n || c < 0)
            return false;
        if (grid[r][c] == 1) {
            return true;
        }
        grid[r][c] = 1; // used to marked visited
        int leftclose = dfs(grid, r, c - 1);
        int rightclose = dfs(grid, r, c + 1);
        int upclose = dfs(grid, r - 1, c);
        int downclose = dfs(grid, r + 1, c);

        return leftclose && rightclose && upclose && downclose;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j) == true) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
