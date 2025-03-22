//T.C : O(n*(v*e))
//S.C : O(n)

class Solution {
public:
    void dfs(int i, unordered_map<int,vector<int>>&mpp, int &e_cnt, int &v_cnt, vector<int>&vis){
        vis[i]=1;
        v_cnt++;
        e_cnt+=mpp[i].size();

        for(auto vec:mpp[i]){
            if(!vis[vec]){
                dfs(vec,mpp,e_cnt,v_cnt,vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mpp;
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        vector<int>vis(n,0);
        int ans=0;
        for(int i=0; i<n; i++){
            int e_cnt=0;
            int v_cnt=0;
            if(!vis[i]){
                dfs(i,mpp,e_cnt,v_cnt,vis);
                if(e_cnt==(v_cnt)*(v_cnt-1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
