class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        using lli=long long int;
        int n=prices.size();
        lli i=0,j=1,res=0;
        while(j<n){
            if(prices[j-1]==prices[j]+1){
                res+=j-i;
                j++;
            }
            else{
                i=j;j++;
            }
        }
        return res+n;
    }
};
