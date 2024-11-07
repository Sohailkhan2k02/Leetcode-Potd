//T.C : O(24*n)
//S.C : O(1)
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for(int i=0;i<24;i++){
            int cnt = 0;
            for(auto &x:candidates){
                cnt+=((x&(1<<i))>0);
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
