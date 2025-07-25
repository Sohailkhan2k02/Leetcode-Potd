class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0 && nums[i] > 0; i--)
            if(nums[i] != nums[i + 1])
                ans += nums[i];
        return ans;
    }
};
