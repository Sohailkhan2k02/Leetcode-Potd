class Solution {
public:
    int compute(string &s,int i,int j,int n, vector<vector<int>> &dp){
        if(i>=n || j>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            dp[i][j] = 1 + compute(s,i+1,j+1,n,dp);
        }else{
            dp[i][j] = 0;
        }
        return dp[i][j];
    }
    int findPar(int u, vector<int> &parent){
        if(u == parent[u]) return u;
        return parent[u] = findPar(parent[u],parent);
    }
    void doUnion(int u,int v,vector<int> &rank, vector<int> &parent){
        u = findPar(u,parent);
        v = findPar(v,parent);
        if(u == v) return;
        if(rank[u] > rank[v]) parent[v] = u;
        else if(rank[u] < rank[v]) parent[u] = v;
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    string findTheString(vector<vector<int>>& lcp) {
        int m = lcp.size(), n = lcp[0].size();
        vector<int> parent(n), rank(n,0);
        for(int i=0;i<n;i++) parent[i] = i;
        for(int i=0;i<m;i++){
            if(lcp[i][i] != (m-i)) return "";
            for(int j=i+1;j<n;j++){
                if(lcp[i][j] != lcp[j][i] || lcp[i][j] > (m-j)) return "";
                // Create the DSU
                if(lcp[i][j]) doUnion(i,j,rank,parent);
            }
        }
        // for(int i=0;i<n;i++)cout<<i<<", "<<parent[i]<<endl;
        // Build the string
        string res;
        int nextChar = 'a';
        for(int i=0;i<n;i++){
            if(parent[i] == i){
                if(nextChar <= 'z') res.push_back((char)nextChar);
                else return "";
                nextChar++;
            }else{
                res.push_back(res[parent[i]]);
            }
        }
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                compute(res,i,j,n,dp);
            }
        }
        // cout<<res<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++) cout<<dp[i][j]<<", ";
        //     cout<<endl;
        // }
        return dp == lcp?res:"";
    }
};
