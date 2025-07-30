class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int mxx=0,maxi=-1,len=0;
        for(int i=0; i<n; i++){
            if(nums[i]>mxx){
                mxx=nums[i];
                len=0;
                maxi=0;
            }
            if(nums[i]==mxx){
                len++;
            }
            else len=0;
            maxi=max(maxi,len);
        }
        return maxi;
    }
};
