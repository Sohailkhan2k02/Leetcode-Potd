class Solution {
public:
    int minimumArea(vector<vector<int>>& x2) {
      int x3 = x2.size();
    int x4 = x2[0].size();

    int mnr = x3, mxr = -1;
    int mnc = x4, mxc = -1;

    for (int i = 0; i < x3; ++i) {
        for (int j = 0; j < x4; ++j) {
            if (x2[i][j] == 1) {
                mnr = min(mnr, i);
                mxr = max(mxr, i);
                mnc = min(mnc, j);
                mxc = max(mxc, j);
            }
        }
    }

    if (mxr == -1) {
        return 0;
    }

    int a = (mxr - mnr + 1) * (mxc - mnc + 1);
    return a;
    }
};
