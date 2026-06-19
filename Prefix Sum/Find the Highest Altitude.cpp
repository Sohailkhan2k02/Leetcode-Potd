class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> pre(n+1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i-1] + gain[i-1];
        }
        for(int i=0; i<n; i++){
            cout<<pre[i]<<" ";
        }
        return *max_element(pre.begin(),pre.end());
    }
};
