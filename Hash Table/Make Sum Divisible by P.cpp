//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        using ll=long long;
        int n=nums.size();
        ll t=accumulate(nums.begin(),nums.end(),0LL,[&](ll sum, int num){
            return (sum+num)%p;
        });
        if(t%p==0) return 0;
        unordered_map<int,int>mpp;
        ll sum=0,len=n;
        mpp[0]=-1;
        for(int i=0; i<n; i++){
            sum=(sum+nums[i])%p;
            ll rem=(sum-t+p)%p;
            if(mpp.find(rem)!=mpp.end()){
                len=min(len,(ll)i-mpp[rem]);
            }
            mpp[sum]=i;
        }
        if(len==n){
            return -1;
        }
        return len;
    }
};
