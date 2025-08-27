int dx[] = {-1, 1, 1, -1};
int dy[] = {1, 1, -1, -1};
class Solution {
public:
    int solve(vector<vector<vector<vector<int>>>> &dp,int i, int j, int dir, int allowed, vector<vector<int>>& grid,
              int target) {

        

        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() ||
            target != grid[i][j]) {
            return 0;
        }

        if(dp[i][j][dir][allowed]!=-1){
            return dp[i][j][dir][allowed];
        }

        int noChange =
            1 + solve(dp,i + dx[dir], j + dy[dir], dir, allowed, grid, 2 - target);

        int Change = 0;

        if (allowed) {
            Change = 1+solve(dp,i + dx[(dir + 1) % 4], j + dy[(dir + 1) % 4],
                           (dir + 1) % 4, 0, grid, 2-target);
        }

        return dp[i][j][dir][allowed]=max(Change, noChange);
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(4,vector<int>(2,-1))));

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;

                        maxi = max(maxi, 1 + solve(dp,nx, ny, k, 1, grid, 2));
                    }
                }
            }
        }

        return maxi;
    }
};
