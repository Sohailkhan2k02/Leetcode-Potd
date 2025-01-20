//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

    unordered_map<int,int>mp;
    for(int i = 0; i < arr.size(); i++) {
        mp[arr[i]] = i;
    }

    int minIndex = INT_MAX , maxIndex = INT_MIN;
    int rowSize = mat.size();
    int colSize = mat[0].size();

    for(int row = 0; row < rowSize; row++) {
        maxIndex = INT_MIN;
        for(int column = 0; column < colSize; column++) {
            int indexVal = mp[mat[row][column]];
            maxIndex = max(maxIndex , indexVal);
        }
        minIndex = min(minIndex , maxIndex);
    }
    
    for(int column = 0; column < colSize; column++) {
        maxIndex = INT_MIN;
        for(int row = 0; row < rowSize; row++) {
            int indexVal2 = mp[mat[row][column]];
            maxIndex = max(maxIndex , indexVal2);
        }
        minIndex = min(minIndex , maxIndex);
    }
    return minIndex;   
}
};    
