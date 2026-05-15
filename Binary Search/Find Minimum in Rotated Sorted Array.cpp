class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<h){
            int m=l+(h-l)/2;
            if(nums[m]>nums[h]){
                l=m+1;
            }
            else h=m;
        }
        return nums[h];
    }
};
