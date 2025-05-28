class Solution {
public:
    // int f(int src,int dest,unordered_map<int,vector<int>>&m1, unordered_map<int,vector<int>>&m2, int k){
    //     int cnt=0;
    //     if(k<1){
    //         cnt=1;
    //     }
    //     else{
    //         cnt=2;
    //     }
    //     unordered_set<int>vis;
    //     queue<pair<int,int>>q;
    //     q.push({src,0});   
    //     q.push({dest,0});
    //     while(!q.empty()){
    //         int node=q.front().first;
    //         int d=q.front().second;
    //         q.pop();
    //         vis.insert(node);
    //         cnt++;
            
    //         if(d>k || vis.find(node)!=vis.end()) continue;
    //         for(auto i:m1[node]){
    //             q.push({i,d+1});
    //         }
    //         for(auto i:m2[node]){
    //             q.push({i,d+1});
    //         }
    //     }
    //     return cnt;
    // }
    int f(int i, unordered_map<int,vector<int>>&m1, int n, int k){
        queue<int>q;
        unordered_set<int>st;
        q.push(i);
        st.insert(i);
        int cnt=0,level=0;
        while(!q.empty() && level<=k){
            int N=q.size();
            while(N--){
                int node=q.front();
                q.pop();
                cnt++;
                for(auto it:m1[node]){
                    if(st.find(it)==st.end()){
                        st.insert(it);
                        q.push(it);
                    }
                }
            }
            level++;
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=0,m=0;
        unordered_map<int,vector<int>>m1,m2;
        for(auto i:edges1){
            int u=i[0],v=i[1];
            n=max(u,v);
            m1[u].push_back(v);
            m1[v].push_back(u);
        }
        for(auto i:edges2){
            int u=i[0],v=i[1];
            m=max(u,v);
            m2[u].push_back(v);
            m2[v].push_back(u);
        }
        n+=1,m+=1;
        vector<int>cnt(n,0);
        for(int i=0; i<n; i++){
            cnt[i]=f(i,m1,n,k);
        }
        // for(auto i:cnt) cout<<i<<" ";
        int mxxcnt=0;
        for(int i=0; i<m; i++){
            mxxcnt=max(mxxcnt,f(i,m2,m,k-1));
        }
        vector<int>res(n,0);
        for(int i=0; i<n; i++){
            res[i]=cnt[i]+mxxcnt;
        }
        return res;
    }
};
