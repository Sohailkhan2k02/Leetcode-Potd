//T.C : O(n*m)
//S.C : O(m)+O(m)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        unordered_map<string,int>mpp;
        int cnt=0;
        for(int i=0; i<n; i++){
            string pat="";
            for(int j=0; j<m; j++){
                pat+="#";
                if(j<m-1 && (mat[i][j]!=mat[i][j+1])){
                    pat+="!";
                }
            }
            mpp[pat]++;
            cnt=max(cnt,mpp[pat]);
        }
        return cnt;
    }
};
