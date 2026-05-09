class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> elements;

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            // top row
            for (int j = left; j <= right; j++) {
                elements.push_back(grid[top][j]);
            }

            // right column
            for (int i = top + 1; i <= bottom - 1; i++) {
                elements.push_back(grid[i][right]);
            }

            // bottom row
            for (int j = right; j >= left; j--) {
                elements.push_back(grid[bottom][j]);
            }

            // left column
            for (int i = bottom - 1; i >= top + 1; i--) {
                elements.push_back(grid[i][left]);
            }

            int len = elements.size();
            int rotate = k % len;

            vector<int> rotated(len);

            for (int i = 0; i < len; i++) {
                rotated[i] = elements[(i + rotate) % len];
            }

            int idx = 0;

            // top row
            for (int j = left; j <= right; j++) {
                grid[top][j] = rotated[idx++];
            }

            // right column
            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = rotated[idx++];
            }

            // bottom row
            for (int j = right; j >= left; j--) {
                grid[bottom][j] = rotated[idx++];
            }

            // left column
            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = rotated[idx++];
            }
        }

        return grid;
    }
};
