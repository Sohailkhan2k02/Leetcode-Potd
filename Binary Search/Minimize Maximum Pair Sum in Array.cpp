class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        int maxi=0;
        while(i<j){
            int sum=nums[i]+nums[j];
            maxi=max(maxi,sum);
            i++;
            j--;
        }
        return maxi;
    }
};
