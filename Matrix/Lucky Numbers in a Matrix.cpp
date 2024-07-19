//T.C : O(n*n)
//S.C: O(n)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>res;
        for(int i=0; i<n; i++){
            int mini=INT_MAX,i2=-1;
            for(int j=0; j<m; j++){
                if(mini>matrix[i][j]){
                    i2=j;
                    mini=matrix[i][j];
                }
            }
            // cout<<mini<<" ";
            int maxi=INT_MIN;
            for(int k=0; k<n; k++){
                maxi=max(maxi,matrix[k][i2]);
            }
            cout<<maxi<<" ";
            if(mini==maxi){
                res.push_back(mini);
            }
        }
        return res;
    }
};
