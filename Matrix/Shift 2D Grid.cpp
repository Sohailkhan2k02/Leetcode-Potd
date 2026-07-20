class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& nums, int k) {
        queue<int> q;
        int n = nums.size();
        int m = nums[0].size();

        k %= (n * m);
        int idx = (n * m) - k;

        for (int t = 0; t < k; t++) {
            int i = idx / m;
            int j = idx % m;
            q.push(nums[i][j]);
            idx++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                q.push(nums[i][j]);
                nums[i][j] = q.front();
                q.pop();
            }
        }

        return nums;
    }
};
