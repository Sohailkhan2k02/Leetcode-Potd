class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& A) {
        int n = A.size(), m = A[0].size(), res = 0;
        vector<pair<int,int>> dp(m);
        for(auto& vec : A) {
            int sum = 0, fl = 0;
            for(int i = 0; i < m; i++) {
                if(vec[i] == 'X') {
                    fl = 1;
                    sum++;
                } else if(vec[i] == 'Y') {
                    sum--;
                }
                dp[i].first |= fl;
                dp[i].second += sum;
                if(dp[i].first and dp[i].second == 0) res++;
            }
        }
        return res;
    }
};
