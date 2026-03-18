class Solution {
public:
    int f(vector<vector<int>>& grid, int k) {
       int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    // Calculate prefix sum matrix
    vector<vector<int>> prefix_sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }

    // Count submatrices
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int x = i; x > 0; --x) {
                for (int y = j; y > 0; --y) {
                    int submatrix_sum = prefix_sum[i][j] - prefix_sum[x - 1][j] - prefix_sum[i][y - 1] + prefix_sum[x - 1][y - 1];
                    if (submatrix_sum <= k) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
    }
    int countSubmatrices(vector<vector<int>>& yeti, int k) {
    int ptr = 0;
    int rtr = yeti.size();
    int raticate = yeti[0].size();
        
    for (int yeti_row = 0; yeti_row < rtr; yeti_row++) {
        for (int yeti_col = 1; yeti_col < raticate; yeti_col++) {
            yeti[yeti_row][yeti_col] += yeti[yeti_row][yeti_col - 1];
        }
    }
        
    for (int jj = 0; jj < raticate; jj++) {
        int ghg = 0;
        for (int rtr_end = 0; rtr_end < rtr; rtr_end++) {
            ghg += yeti[rtr_end][jj];
            if(ghg <= k) ptr++;
        }
    }
        
    return ptr;
}
};
