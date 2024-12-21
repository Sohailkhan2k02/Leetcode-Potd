//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    using ll=long long;
    ll cnt=0;
    ll f(int i, int n, vector<int>adj[],vector<int>&values,vector<int>&vis, int k){
        if(vis[i]) return 0;
        vis[i]=1;
        ll sum=values[i];
        for(auto vec:adj[i]){
            sum+=f(vec,n,adj,values,vis,k);
        }
        if(sum%k==0){
            cnt++;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>adj[n];
        for(auto i:edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        f(0,n,adj,values,vis,k);
        return cnt;
    }
};
