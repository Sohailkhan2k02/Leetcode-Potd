//T.C : O(n*n)
//S.C : O(n*n)
class DisjointSet{
    public :
    vector<int>parent,rank,size;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);
        for(int i = 0 ;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUPar(int u){
        if(u == parent[u]){
            return u;
        }
        else{
            return parent[u]=findUPar(parent[u]);
        }
    }
    void unionByRank(int u,int v){

    }
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u== ulp_v){
            return;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int row =0;row<n;row++){
            for(int col = 0;col<n;col++){
                if(grid[row][col]==0){
                    continue;
                }
                int delrow[]={-1,0,1,0};
                int delcol[]={0,1,0,-1};
                for(int i =0;i<4;i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow >=0 && nrow <n && ncol >=0 && ncol<n && 
                    grid[nrow][ncol]==1){
                        int node = row*n + col;
                        int adjnode = nrow*n + ncol;
                        ds.unionBySize(node,adjnode);
                    }
                }
            }
        }
        int ans=0;
        for(int row =0;row<n;row++){
            for(int col =0;col<n;col++){
                if(grid[row][col]==1){
                    continue;
                }
                set<int>st;
                int delrow[]={-1,0,1,0};
                int delcol[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow >=0 && nrow<n && ncol >=0 && ncol<n 
                    && grid[nrow][ncol]==1){
                        int adjnode = nrow*n+ncol;
                        st.insert(ds.findUPar(adjnode));
                    }
                }
                int tempsize=0;
                for(auto it : st){
                    tempsize+=ds.size[it];
                }
                ans = max(ans,tempsize + 1);
            }
        }
        for(int i=0;i<n*n;i++){
            ans = max(ans,ds.size[ds.findUPar(n)]);
        }
        return ans;
    }
};
