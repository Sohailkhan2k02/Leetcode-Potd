using ll=long long;
constexpr int N=1<<15;
ll dp[N];
class Solution {
public:
    static ll f(long long x, unsigned bitMask){
        ll cnt=0;
        for(unsigned i=1; i<=bitMask; i++)
            cnt+=(popcount(i)&1)?(x/dp[i]):(-x/dp[i]);
        return cnt;
    }

    static long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end(), greater<>());
        if (coins.back()==1) return k;
        bitset<26> valid_coin=0;
        for (int c: coins){
            valid_coin[c]=1;
            for(int r=2*c; r<26; r+=c) valid_coin[r]=0;
        }
        coins.clear();
        for(int i=1; i<=25; i++) 
            if(valid_coin[i]) coins.push_back(i);

        int sz=coins.size();
        if (sz==1) return (ll)coins[0]*k;

        unsigned bitMask=(1<<sz)-1;
        memset(dp, -1, (1<<sz)*sizeof(ll));

        // Loop through all possible subsets of coins
        for (int bMask=1; bMask<=bitMask; bMask++) {
            ll lcm=1;
            for (int i=0; i<sz; i++) {
                if (bMask & (1LL<<i)) {
                    lcm=lcm/gcd(lcm, coins[i])*coins[i] ; // compute LCM
                }
            }
            dp[bMask]=lcm;
        }
       
        ll l=k+1, r=(ll)coins[0]*k, mid, ans=r;

        while (l<=r) {
            mid=l+(r-l)/2;
            if (f(mid, bitMask)>=k){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
