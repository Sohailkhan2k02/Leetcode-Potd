//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,k=i+1;
        int cnt=0;
        while(j<n){
            if(j-i+1==3){
                if(nums[i]+nums[j]==(nums[k]/2.0)) {
                    cnt++;
                    // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]/2.0<<" ";
                }
                i++;
                k++;
            }
            j++;
        }
        return cnt;
    }
};
