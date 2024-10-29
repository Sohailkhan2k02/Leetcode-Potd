//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, int n, int m, int prev,vector<vector<int>>&dp) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] <= prev) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int delrow[] = {-1, 0, 1};
        int delcol[] = {1, 1, 1};
        int mxx = 0;
        
        for (int k = 0; k < 3; k++) {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            mxx = max(mxx, 1+f(nrow, ncol, grid, n, m, grid[i][j],dp));
        }
        
        return dp[i][j] = mxx;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m, -1));
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, f(i, 0, grid, n, m, -1,dp));
        }
        return maxi-1;
    }
};
