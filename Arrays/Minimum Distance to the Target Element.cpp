class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minv = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                minv = min(minv,abs(i-start));
            }
        }
        return minv;
    }
};
