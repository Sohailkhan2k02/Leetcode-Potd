class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        array<array<int, 51>, 52> d1{}, d2{};
        set<int> st;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
                d2[i + 1][j + 1] = d2[i][j + 2] + grid[i][j];
                st.insert(grid[i][j]);
                if (st.size() > 3)
                    st.erase(st.begin());
            }
        }
        for (int w = 1; w <= min(m, n) / 2; ++w) {
            for (int i = 0; i < m - w * 2; ++i) {
                for (int j = w; j < n - w; ++j) {
                    int sum = grid[i][j] + grid[i + w][j + w] + grid[i + w * 2][j] + grid[i + w][j - w];
                    int ab = d1[i + w + 1][j + w + 1] - d1[i][j];
                    int dc = d1[i + w * 2 + 1][j + 1] - d1[i + w][j - w];
                    int ad = d2[i + w + 1][j - w + 1] - d2[i][j + 2];
                    int bc = d2[i + w * 2 + 1][j + 1] - d2[i + w][j + w + 2];
                    sum = ab + dc + ad + bc - sum;
                    st.insert(sum);
                    if (st.size() > 3)
                        st.erase(st.begin());
                }
            }
        }
        return {rbegin(st), rend(st)};
    }
};
