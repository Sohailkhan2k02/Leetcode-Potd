//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(),m=box[0].size();
        vector<vector<char>>rotate_box(m,vector<char>(n,'.'));
        for(int i=0; i<n; i++){
            int new_j=m-1;
            for(int j=m-1; j>=0; j--){
                if(box[i][j]=='#'){
                    rotate_box[new_j][n-i-1]='#';
                    new_j--;
                }
                else if(box[i][j]=='*'){
                    rotate_box[j][n-i-1]='*';
                    new_j=j-1;
                }
            }
        }
        return rotate_box;
    }
};
