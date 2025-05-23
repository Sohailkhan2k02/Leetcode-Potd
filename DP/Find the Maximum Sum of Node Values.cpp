//T.C : O(n)
//S.C : O(1)
#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        ll sum=0,cnt=0;
        int mini=INT_MAX;
        for(ll i=0; i<n; i++){
            if((nums[i]^k)>nums[i]){
                cnt++;
                sum+=nums[i]^k;
            }
            else{
                sum+=nums[i];
            }

            mini=min(mini,abs(nums[i]-(nums[i]^k)));
        }
        if(cnt%2==0){
            return sum;
        }
        return sum-mini;
    }
};
