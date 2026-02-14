class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
      double list[101][101] = {0};
      list[0][0] = poured;              
    for(int i =0; i<=query_row; i++) {
      for(int j=0; j<i+1; j++) {
        if(list[i][j]>1) {
            list[i+1][j] =   list[i+1][j] + (list[i][j]-1)/2.0; 
            list[i+1][j+1] = list[i+1][j+1] + (list[i][j]-1)/2.0;    
            list[i][j] = 1; 
            }
        }
    }
    if(list[query_row][query_glass]>1) return 1;
    else return list[query_row][query_glass];
}
    
};
