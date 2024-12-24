//T.C : O(V+E) OF TREE1 + O(V+E) OF TREE 2
//S.C : O(N+M)
class Solution {
public:
    pair<int,int>bfs(int start, vector<int>adj[], int n,vector<int>&vis){
        queue<int>q;
        q.push(start);
        vis[start]=1;
        int level=0;
        int farthestNode=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                farthestNode=q.front();q.pop();
                for(auto vec:adj[farthestNode]){
                    if(!vis[vec]){
                        q.push(vec);
                        vis[vec]=1;
                    }
                }
            }
            level++;
        }
        return {level-1,farthestNode};
    }
    int f(int start, vector<int>adj[], int n,vector<int>&vis){
        auto [d1,A]=bfs(start,adj,n,vis);
        vis=vector<int>(n,0);
        auto [d2,B]=bfs(A,adj,n,vis);
        return d2;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<int>adj1[n],adj2[m];
        for(auto i:edges1){
            int u=i[0],v=i[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto i:edges2){
            int u=i[0],v=i[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<int>vis1(n,0),vis2(m,0);
        int dA=f(0,adj1,n,vis1);
        int dB=f(0,adj2,m,vis2);
        return max({dA,dB,(dA+1)/2 + (dB+1)/2 + 1});
    }
};
