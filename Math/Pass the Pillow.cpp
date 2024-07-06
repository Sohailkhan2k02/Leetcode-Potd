//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int passThePillow(int n, int t) {
        int tt=t%(2*(n-1));
        if(tt>=n-1){
            return n-(tt-(n-1));
        }
        return tt+1;
    }
};
