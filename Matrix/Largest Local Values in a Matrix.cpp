//T.C : O(n^2*3)
//S.C : O(n^2)

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& g) {
        int n=g.size();
        vector<vector<int>>res(n-2,vector<int>(n-2,0));
        for(int i=0; i<n-2; i++){
            for(int j=0; j<n-2; j++){
                for(int x=i; x<i+3; x++){
                    for(int y=j; y<j+3; y++){
                        res[i][j]=max(res[i][j],g[x][y]);
                    }
                }
            }
        }
        return res;
    }
};
