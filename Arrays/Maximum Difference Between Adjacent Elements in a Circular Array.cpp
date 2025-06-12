class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [&,i=-1](int ans, int x) mutable{
            return ans=(++i==0)?max(ans,abs(nums.back()-x)):max(ans, abs(nums[i-1]-x));
        });
    }
};
