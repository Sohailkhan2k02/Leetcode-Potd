//T.C : O(Q*(V+E))
//S.C : O(V+E)
class Solution {
public: 
    int i=0;
    void f(int n,unordered_map<int,vector<int>>&mpp,vector<int>&res){
        vector<int>dis(n,INT_MAX);
        queue<int>q;
        dis[0]=0;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto adjnode:mpp[node]){
                if(dis[adjnode]>dis[node]+1){
                    dis[adjnode]=dis[node]+1;
                    q.push(adjnode);
                }
            }
        }
        res[i++]=dis[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0; i<n-1; i++){
            mpp[i].push_back(i+1);
        }
        vector<int>res(queries.size(),INT_MAX);
        for(auto i:queries){
            int u=i[0],v=i[1];
            mpp[u].push_back(v);
            f(n,mpp,res);
        }
        return res;
    }
};
