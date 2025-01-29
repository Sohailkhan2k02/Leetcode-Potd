//T.C : O(n)
//S.C : O(n)
class DSU{
    vector<int>parent,rank;
    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int findUpr(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUpr(parent[node]);
    }
    void UnionByRank(int u, int v){
        int x=findUpr(u),y=findUpr(v);
        if(x==y) return;
        if(rank[x]<rank[y]){
            parent[x]=y;
        }
        else if(rank[x]>rank[y]){
            parent[y]=x;
        }
        else{
            parent[x]=y;
            rank[y]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU ds(n);
        for(int i=0; i<n; i++){
            int u=edges[i][0],v=edges[i][1];
            if(ds.findUpr(u)==ds.findUpr(v)){
                return {u,v};
            }
            else{
                ds.UnionByRank(u,v);
            }
        }
        return {-1,-1};
    }
};
