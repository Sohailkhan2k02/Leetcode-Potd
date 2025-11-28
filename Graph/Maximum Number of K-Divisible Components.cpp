class Solution {
public:
    //DFS - 1ST APPROACH 
    // using ll=long long;
    // ll cnt=0;
    // ll f(int i, int n, vector<int>adj[],vector<int>&values,vector<int>&vis, int k){
    //     if(vis[i]) return 0;
    //     vis[i]=1;
    //     ll sum=values[i];
    //     for(auto vec:adj[i]){
    //         sum+=f(vec,n,adj,values,vis,k);
    //     }
    //     if(sum%k==0){
    //         cnt++;
    //     }
    //     return sum;
    // }
    // int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    //     vector<int>adj[n];
    //     for(auto i:edges){
    //         int u=i[0],v=i[1];
    //         adj[u].push_back(v);
    //         adj[v].push_back(u);
    //     }
    //     vector<int>vis(n,0);
    //     f(0,n,adj,values,vis,k);
    //     return cnt;
    // }

    // 2ND APPROACH - TOPOLOGICAL SORT
    using ll=long long;
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k){
        if(n<2) return 1;
        queue<int>q;
        vector<int>indegree(n,0);
        vector<int>adj[n];
        vector<ll>nodeval(values.begin(),values.end());
        for(auto i:edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        for(int i=0; i<n; i++){
            if(indegree[i]==1) q.push(i);
        }
        ll cnt=0;
        while(!q.empty()){
            int curr=q.front(); q.pop();
            indegree[curr]--;
            ll addval=nodeval[curr];
            if(nodeval[curr]%k==0){
                cnt++;
                addval=0;
            }
            for(auto vec:adj[curr]){
                if(indegree[vec]>0){
                    indegree[vec]--;
                    nodeval[vec]+=addval;
                    if(indegree[vec]==1) q.push(vec);
                }
            }
        }
        return cnt;
    }
};
