class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int col = strs[0].size();  
        int row = strs.size();     
        int res = 0;  
        vector<bool> sorted_pairs(row - 1, false);  
        for (int c = 0; c < col; ++c) {
            bool check = true;  
            for (int r = 0; r < row - 1; ++r) {
                if (!sorted_pairs[r] && strs[r][c] > strs[r + 1][c]) {
                    check = false;  
                    break;
                }
            }
            if (check == false) {
                res++;  
                continue; 
            }
            for (int r = 0; r < row - 1; ++r) {
                if (!sorted_pairs[r] && strs[r][c] < strs[r + 1][c]) {
                    sorted_pairs[r] = true;  
                }
            }
        }
        return res;
    }
};
