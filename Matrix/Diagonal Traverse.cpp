class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<int,vector<int>>mpp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mpp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>res;
        for(auto it:mpp){
            if(it.first%2==0){
                for(int i=it.second.size()-1; i>=0; i--){
                    res.push_back(it.second[i]);
                }
            }
            else{
                for(int i=0; i<it.second.size(); i++){
                    res.push_back(it.second[i]);
                }
            }
        }
        return res;
    }
};
