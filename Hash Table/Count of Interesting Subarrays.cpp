//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        using ll=long long;
        int n=nums.size();
        unordered_map<ll,ll>mpp;
        mpp[0]=1;
        ll cnt=0,res=0;
        int i=0,j=0;
        for(int i=0;i<n; i++){
            if(nums[i]%modulo==k) cnt++;
            ll md=cnt%modulo;
            ll nd=(md-k+modulo)%modulo;
            res+=mpp[nd];
            mpp[md]++;
        }
        return res;
    }
};
