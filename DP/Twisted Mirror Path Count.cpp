class Solution {
public:
    int n, m;
    long long mod = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
        return (solve(0, 1, grid, 0, dp)%mod + solve(1, 0, grid, 1, dp)%mod)%mod;
    }
    int solve(int i, int j, vector<vector<int>>& grid, int downDirection, vector<vector<vector<int>>> &dp)
    {
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j][downDirection]!=-1) return dp[i][j][downDirection];

        if(grid[i][j])
        {
            if(downDirection)
            {
                return dp[i][j][downDirection] = solve(i, j+1, grid, 0, dp)%mod;
            }
            return dp[i][j][downDirection] = solve(i+1, j, grid, 1, dp)%mod;
        }

        int path1 = solve(i+1, j, grid, 1, dp);
        int path2 = solve(i, j+1, grid, 0, dp);

        return dp[i][j][downDirection] = (path1%mod + path2%mod)%mod;
    }
};
