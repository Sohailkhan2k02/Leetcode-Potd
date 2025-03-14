//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    using ll=long long;
    bool f(int c, vector<int>&candies, long long k){
        int n=candies.size();
        ll sum=accumulate(candies.begin(),candies.end(),0ll);
        if(sum<k) return false;
        ll cnt=0;
        for(int i=0; i<n; i++){
            cnt+=candies[i]/c;
            if(cnt>=k) return true;
        }
        return cnt>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int l=1,h=*max_element(candies.begin(),candies.end());
        int res=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(f(mid,candies,k)){
                res=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return res;
    }
};
