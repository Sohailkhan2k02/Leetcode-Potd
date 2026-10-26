class Solution {
public:
    long long int BFS(int r, int c, vector<vector<int>>& grid,
                      vector<vector<bool>>& visited) {
        long long int score = grid[r][c];

        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;

        vector<vector<int>> dir = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int m = grid.size();
        int n = grid[0].size();

        while (!q.empty()) {
            auto [n_r, n_c] = q.front();
            q.pop();

            for (auto& d : dir) {
                int x = n_r + d[0];
                int y = n_c + d[1];

                if (x >= 0 && x < m && y >= 0 && y < n &&
                    grid[x][y] != 0 && !visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                    score += grid[x][y];
                }
            }
        }

        return score;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] != 0) {
                    long long int score = BFS(i, j, grid, visited);
                    result += (score % k == 0) ? 1 : 0;
                }
            }
        }

        return result;
    }
};
