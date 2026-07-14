// this is bottom up code
class Solution {
public:
const int mod = 1000000007;
inline int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
    int subsequencePairCount(vector<int>& nums) {
        int size = nums.size();    
        int maxi = *max_element(nums.begin(),nums.end());
        int dp[size+1][maxi+1][maxi+1];
        int gcd_dp[maxi+1][maxi+1];

        memset(dp,0,sizeof(dp));
        memset(gcd_dp,0,sizeof(gcd_dp));

        for(int i=0;i<=maxi;i++)
        {
            if(i>0)
                dp[size][i][i] = 1;

            for(int j=0;j<=maxi;j++)
            {
                if(i==0 || j==0)    gcd_dp[i][j] = 0;   

                int val = gcd(i,j);

                gcd_dp[i][j] = val;
                gcd_dp[j][i] = val;
            }
        }

        for(int index=size-1;index>=0;index--)
        {
            for(int seq1 = 0;seq1<=maxi;seq1++)
            {
                for(int seq2 = 0;seq2<=maxi;seq2++)
                {
                    dp[index][seq1][seq2] = (1LL*dp[index+1][gcd_dp[seq1][nums[index]]][seq2] + 1LL*dp[index+1][seq1][gcd_dp[seq2][nums[index]]] + 1LL*dp[index+1][seq1][seq2])%mod;    

                }
            }
        }

        return dp[0][0][0];
    }
};
