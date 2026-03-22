class Solution {
public:

    vector<vector<int>> rotate90(vector<vector<int>> &mat){

        int n = mat.size();

        vector<vector<int>> res(n, vector<int>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                res[j][n-1-i] = mat[i][j];
            }
        }

        return res;
    }

    bool same(vector<vector<int>> &a, vector<vector<int>> &b){

        int n = a.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(a[i][j] != b[i][j])
                    return false;
            }
        }

        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        for(int k = 0; k < 4; k++){

            if(same(mat, target))
                return true;

            mat = rotate90(mat);
        }

        return false;
    }
};
