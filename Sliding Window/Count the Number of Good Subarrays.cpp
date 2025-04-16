//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        using ll=long long;
        ll n=nums.size();
        unordered_map<ll,ll>mpp;
        ll i=0,j=0,cnt=0,c1=0;
        while(j<n){
            c1+=mpp[nums[j]];
            mpp[nums[j]]++;
            while(c1>=k){
                cnt+=n-j;
                c1-=mpp[nums[i]]-1;
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return cnt;
    }
};
