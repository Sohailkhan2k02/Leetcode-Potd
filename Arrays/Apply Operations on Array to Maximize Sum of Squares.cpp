class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
         vector<int> bit(31);
        for(auto ele : nums)
        {
            for(int j=0;j<=30;j++)
            {
                int rep=(1<<j);
                if(ele&rep)
                    bit[j]++;
            }
        }
        
        vector<long long> vals(k);
        for(int i=30;i>=0;i--)
        {
            long long rep=(1ll<<i);
            for(int j=0;j<std::min(bit[i],k);j++)
                vals[j]+=rep;
        }
        
        long long ans=0ll;
        const int mod=1e9+7;
        for(auto ele : vals)
            ans=(ans+ele*1ll*ele)%mod;
        return ans;
    }
};
