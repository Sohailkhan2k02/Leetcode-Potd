class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& mat){
        m = mat.size();
        n = mat[0].size();
        int count = 0;
        int bou = n;
        
        for(int a = i; a < m; a++){
            if(mat[a][j] == 0) break;
            for(int b = j; b < bou; b++){
                if(mat[a][b]) count += 1;
                else{
                    bou = b;
                    break;
                }
            }
        }
        return count;
    }
    int numSubmat(vector<vector<int>>& mat) {

        m = mat.size();
        n = mat[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                count += solve(i, j, mat);
            }
        }
        return count;
    }
};
