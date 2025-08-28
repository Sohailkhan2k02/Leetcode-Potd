class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int t = 0; t < n; t++){
            for (int i = 0; i < n - 1; i++){
                for (int j = 0; j < n - 1; j++){
                    if (j > i){
                        if (grid[i][j] > grid[i + 1][j + 1]){
                            swap(grid[i][j], grid[i + 1][j + 1]);
                        }
                    } else {
                        if (grid[i][j] < grid[i + 1][j + 1]){
                            swap(grid[i][j], grid[i + 1][j + 1]);
                        }
                    }
                }
            }
        }
        return grid;
    }
};
