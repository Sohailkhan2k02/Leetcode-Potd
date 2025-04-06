//T.C : O(n*n + nlogn)
//S.C : O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int maxi=1;
        int ind=0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }

                if(dp[i]>maxi){
                    maxi=dp[i];
                    ind=i;
                }
            }
        }
        vector<int>res;
        while(ind>=0){
            res.push_back(nums[ind]);
            ind=prev[ind];
        }
        return res;
    }
};
