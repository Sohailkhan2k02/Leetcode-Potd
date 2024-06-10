//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int heightChecker(vector<int>& h) {
        int n=h.size();
        vector<int>v(h.begin(),h.end());
        sort(h.begin(),h.end());
        int cnt=0;
        for(int i=0; i<n; i++){
            if(v[i]!=h[i]){
                cnt++;
            }
        }
        return cnt;
    }
};
