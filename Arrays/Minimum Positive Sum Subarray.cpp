class Solution {
public:
    int f(vector<int>&nums,int n, int range){
        int sum=0,mini=INT_MAX;
        int i=0,j=0;
        while(j<n){
            sum+=nums[j];
            if(j-i+1==range){
                if(sum>0){
                    mini=min(mini,sum);
                }
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return mini;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=l; i<=r; i++){
            mini=min(mini,f(nums,n,i));
        }
        return mini==INT_MAX?-1:mini;
    }
};
