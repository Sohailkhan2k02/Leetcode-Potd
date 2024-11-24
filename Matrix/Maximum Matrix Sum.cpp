//T.C : O(n*m)
//S.C : O(1)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        using ll=long long;
        int n=matrix.size();
        ll sum=0,mini=INT_MAX,neg=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mini=min(mini,(ll)abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0) neg++;
            }
        }
        if(neg&1){
            sum-=2*mini;
        }
        return sum;
    }
};
