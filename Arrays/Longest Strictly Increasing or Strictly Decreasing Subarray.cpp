//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int inc=1,dec=1;
        int mxx=1;
        for(int i=0; i<n-1; i++){
            if(nums[i]<nums[i+1]){
                inc++;
            }
            else{
                mxx=max(mxx,inc);
                inc=1;
            }
        }
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]){
                dec++;
            }
            else{
                mxx=max(mxx,dec);
                dec=1;
            }
        }
        return max({mxx,dec,inc});
    }
};
