//T.C : O(n*k)
//S.C : O(1)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        while (k--) {
            int ind = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[ind]) ind = i;
            }
            nums[ind] *= m;
        }
    return nums;
    }
};
