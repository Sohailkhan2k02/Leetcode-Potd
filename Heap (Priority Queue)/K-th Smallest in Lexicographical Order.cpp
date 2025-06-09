//T.C : O(n)
class Solution {
public:
    using ll=long long;
    // vector<int>res;
    // void f(int i, int n, int k){
    //     if(i>n) return;
    //     res.push_back(i);

    //     for(int ind=0; ind<=9; ind++){
    //         int newnum=i*10+ind;
    //         if(newnum>n) return;
    //         f(newnum,n,k);
    //     }
    // }
    ll f(ll n, ll curr, ll next){
        ll cnt=0;
        while(curr<=n){
            cnt+=min(n+1,next)-curr;
            curr*=10;
            next*=10;
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        if(n==1) return 1;
        int curr=1;
        k--;
        while(k>0){
            ll cnt=f(n, curr,curr+1);
            if(cnt<=k){
                curr++;
                k-=cnt;
            }else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};
