//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
    std::vector<bool> present(n * n + 1, false);
    std::vector<int> ans(2);

    int sumGrid = 0, sumCorrect = 0, repeat = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int curr = grid[i][j];
            sumGrid += curr;
            sumCorrect += (i * n) + (j + 1);
            if (present[curr]) {
                repeat = curr;
            } else {
                present[curr] = true;
            }
        }
    }

    int missing = repeat + (sumCorrect - sumGrid);
    ans[0] = repeat;
    ans[1] = missing;

    return ans;
    }
};
