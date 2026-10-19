class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;

        int lessThanTargetCount = 0;
        int targetCount = 0;

        for (int num : nums) {
            if (num < target) {
                lessThanTargetCount++;
            }

            if (num == target) {
                targetCount++;
            }
        }

        for (int i = 0; i < targetCount; i++) {
            ans.push_back(lessThanTargetCount + i);
        }

        return ans;
    }
};
