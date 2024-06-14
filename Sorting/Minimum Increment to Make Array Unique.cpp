//T.C : O(N*logN)
//S.C : O(N)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> tmp(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            nums[i] = max(nums[i - 1] + 1, nums[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += abs(nums[i] - tmp[i]);
        }
        return cnt;
    }
};
