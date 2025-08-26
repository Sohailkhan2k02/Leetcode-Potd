class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonalSq = 0; // store diagonal^2 to avoid sqrt
        int maxArea = 0;

        for (auto &v : dimensions) {
            int diagonalSq = v[0]*v[0] + v[1]*v[1];
            int area = v[0] * v[1];

            if (diagonalSq > maxDiagonalSq) {
                maxDiagonalSq = diagonalSq;
                maxArea = area;
            } else if (diagonalSq == maxDiagonalSq) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
