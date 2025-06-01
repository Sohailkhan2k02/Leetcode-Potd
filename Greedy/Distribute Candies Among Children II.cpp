//T.C: O(min(n,limit))
//S.C : O(1)
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res=0;
        for(int i=0; i<=min(n,limit); i++){
            long long mnn=min(limit,n-i);
            long long mxx=max(0,n-i-limit);
            res+=max(mnn-mxx+1,0LL);
        }
        return res;
    }
};
