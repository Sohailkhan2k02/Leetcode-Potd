//Approach-1 (Modifying the input)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(); // number of rows
        int m = grid[0].size(); // number of columns

        // IF FIRST COLUMN IS 0 THEN WE WILL FLIP
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < m; j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        // ELSE IF COUNT OF ZERO IN ONE COLUMN IS GREATER THAN 1 THEN WE WILL FLIP
        for(int j = 1; j < m; j++){
            int cnt = 0;
            for(int i = 0; i < n; i++){
                cnt += grid[i][j];
            }
            if(cnt < n - cnt){
                for(int i = 0; i < n; i++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            int rval = 0;
            for(int j = 0; j < m; j++){
                rval <<= 1;
                rval |= grid[i][j];
            }
            res += rval;
        }
        return res;
    }
};



//Approach-2 (Without Modifying the input)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //MSB -> 2^n-1
        int score = pow(2, n-1) * m;

        for(int j = 1; j < n; j++) {

            int countSameBits = 0; //count of 1s
            for(int i = 0; i < m; i++) {
                if(grid[i][j] == grid[i][0]) {
                    countSameBits++;
                }
            }

            int countOnes  = countSameBits;
            int countZeros = m - countOnes;

            int ones = max(countOnes, countZeros);

            score += (pow(2, n-j-1) * ones);            

            

        }

        return score;
        
    }
};
