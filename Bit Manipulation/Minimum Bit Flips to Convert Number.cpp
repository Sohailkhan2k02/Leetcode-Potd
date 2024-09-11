//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xr=start^goal;
        int cnt=0;
        while(xr){
            xr=(xr&(xr-1));
            cnt++;
        }
        return cnt;
    }
};
