class Solution {
public:
    bool val(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0; i<9; i++){
            if(board[i][col] == ch){
                return false;
            }
            if(board[row][i] == ch){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch){
                return false;
            }
        }
        return true;
    }
    bool gen(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<=9; j++){
                if(board[i][j]!='.') continue;

                for(char ch='1'; ch<='9'; ch++){
                    if(val(board, i, j, ch)){
                        board[i][j] = ch;
                        if(gen(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        gen(board);
    }
};
