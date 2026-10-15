class Solution {
public:
    int sumCounts(vector<int>& nums) {
    int n = nums.size();
    int result = 0;

    for (int i = 0; i < n; i++) {
        unordered_set<int> distinctValues;
        for (int j = i; j < n; j++) {
            distinctValues.insert(nums[j]);
            result += distinctValues.size() * distinctValues.size();
        }
    }

    return result;
    }
};
