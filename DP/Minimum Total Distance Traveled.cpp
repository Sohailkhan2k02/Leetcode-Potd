//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
private:
    long long distance(int i, int j, int n, int m, vector<long long>& rob, vector<long long>& fac, vector<vector<long long>>& dp){
        if (i == n) return 0;
        if (j == m) return 1e13;

        if (dp[i][j] != -1) return dp[i][j];
        
        long long take = distance(i+1,j+1,n,m,rob,fac,dp)+abs(rob[i]-fac[j]);
        long long notTake = distance(i,j+1,n,m,rob,fac,dp);

        return dp[i][j] = min(take,notTake);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        vector<long long> rob,fac;
        for(auto rt: robot){
            rob.push_back(rt);
        }

        for(auto it: factory){
            for(int i = 0 ; i < it[1]; i++){
                fac.push_back(it[0]);
            }
        }

        int n = rob.size();
        int m = fac.size();

        sort(rob.begin(),rob.end());
        sort(fac.begin(),fac.end());


        vector<vector<long long>> dp(n,vector<long long>(m,-1));

        return distance(0,0,n,m,rob,fac,dp);

    }
};
