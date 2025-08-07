class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int ULSum = 0;
        int n = fruits.size();
        for (int i = 0; i < n; i++) {
            ULSum += fruits[i][i];
        }
        for (int i = 1; i < n - 1; i++) {
            for (int j = max(n - i - 1, i + 1); j < n; j++) {
                int LLMaxPrev = 0, URMaxPrev = 0;
                if (j < n - 1) {
                    LLMaxPrev = max(LLMaxPrev, fruits[j + 1][i - 1]);
                    URMaxPrev = max(URMaxPrev, fruits[i - 1][j + 1]);
                }
                if (j > n - i) {
                    LLMaxPrev = max(LLMaxPrev, fruits[j - 1][i - 1]);
                    URMaxPrev = max(URMaxPrev, fruits[i - 1][j - 1]);
                }
                if (j > n - i - 1) {
                    LLMaxPrev = max(LLMaxPrev, fruits[j][i - 1]);
                    URMaxPrev = max(URMaxPrev, fruits[i - 1][j]);
                }
                fruits[j][i] += LLMaxPrev;
                fruits[i][j] += URMaxPrev;
            }
        }
        return ULSum + fruits[n - 1][n - 2] + fruits[n - 2][n - 1];
    }
};
