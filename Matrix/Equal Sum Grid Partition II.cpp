class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        long long totalSum = 0;

        for (auto& row : grid)
            for (int value : row)
                totalSum += value;

        auto canRemove = [&](int top, int bottom, int left, int right, int target,
                             unordered_map<int, int>& freq) {
            int height = bottom - top + 1;
            int width = right - left + 1;

            if (height > 1 && width > 1) return freq.count(target) > 0;
            if (height == 1) return grid[top][left] == target || grid[top][right] == target;
            return grid[top][left] == target || grid[bottom][left] == target;
        };

        auto checkCuts = [&](bool horizontal) {
            unordered_map<int, int> firstPartFreq, secondPartFreq;

            for (auto& row : grid)
                for (int value : row)
                    secondPartFreq[value]++;

            long long firstPartSum = 0;
            int cuts = horizontal ? rows - 1 : cols - 1;
            int length = horizontal ? cols : rows;

            for (int cut = 0; cut < cuts; cut++) {
                for (int i = 0; i < length; i++) {
                    int value = horizontal ? grid[cut][i] : grid[i][cut];
                    firstPartSum += value;
                    firstPartFreq[value]++;
                    if (--secondPartFreq[value] == 0) secondPartFreq.erase(value);
                }

                long long secondPartSum = totalSum - firstPartSum;
                if (firstPartSum == secondPartSum) return true;

                long long difference = llabs(firstPartSum - secondPartSum);
                if (difference > 100000) continue; // impossible to remove one cell

                if (firstPartSum > secondPartSum) {
                    if (horizontal) {
                        if (canRemove(0, cut, 0, cols - 1, (int)difference, firstPartFreq)) return true;
                    } else {
                        if (canRemove(0, rows - 1, 0, cut, (int)difference, firstPartFreq)) return true;
                    }
                } else {
                    if (horizontal) {
                        if (canRemove(cut + 1, rows - 1, 0, cols - 1, (int)difference, secondPartFreq)) return true;
                    } else {
                        if (canRemove(0, rows - 1, cut + 1, cols - 1, (int)difference, secondPartFreq)) return true;
                    }
                }
            }
            return false;
        };

        return checkCuts(true) || checkCuts(false);
    }
};
