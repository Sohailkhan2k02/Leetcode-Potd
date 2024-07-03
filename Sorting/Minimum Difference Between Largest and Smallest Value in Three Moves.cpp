//T.C : O(n*logn)
//S.C : O(1)
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<5) return 0;
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        mini = min({mini, nums[n-4] - nums[0],nums[n-1] - nums[3],nums[n-2] - nums[2],nums[n-3] - nums[1]});
        return mini;
    }
};
