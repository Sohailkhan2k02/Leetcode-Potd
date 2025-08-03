class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int mx = max(startPos + k, fruits[n-1][0]) ; // rightmost bound
        vector<int> pref(mx + 2); // pos0 => 1  posmx =>mx+1 
        for(int i=0;i<n;i++){
            int pos = fruits[i][0], val = fruits[i][1];
            pref[pos+1] = val;
        }
        for(int i=1;i<=mx+1;i++) pref[i] += pref[i-1];
        int ans = 0;
        for(int x=0;x<=k/2;x++){
            int r1 = min(mx, startPos + x);
            int l1 = max(0 , startPos + x - (k-x));
            ans = max(ans, pref[r1+1] - pref[l1]);

            int l2 = max(0, startPos - x);
            int r2 = min(mx, startPos - x + (k-x));
            ans = max(ans, pref[r2+1] - pref[l2]);
        }
        return ans;
    }
};
