class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int n=img1.size(), n2=n*n;
        vector<int> L1, L2;
        L1.reserve(n2), L2.reserve(n2);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) if(img1[i][j]) L1.push_back((i<<10)+j);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) if(img2[i][j]) L2.push_back((i<<10)+j);
        unordered_map<int, int> diff;
        diff.reserve(L1.size()*L2.size());
        for(int x: L1)
            for(int y: L2) diff[x-y]++;
        int ans=0;
        for(auto& [_, f]: diff) ans=max(ans, f);
        return ans;
    }
};
