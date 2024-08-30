//T.C : O(V+E)+O((V+E)LOG(V))+O(E)*O(V+E)LOG(V)
//S.C: O(V+E)+O(V+E)
class Solution {
public:
    int dijkstra(int src,int dst,unordered_map<int,vector<pair<int,int>>>&mpp,int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        while(!pq.empty()) {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto vec:mpp[node]) {
                int adjnode=vec.first;
                int dist=vec.second;
                if(d+dist<dis[adjnode]) {
                    dis[adjnode]=d+dist;
                    pq.push({d+dist,adjnode});
                }
            }
        }
        int res=dis[dst];
        return res;
    }
    vector<vector<int>> modifiedGraphEdges(int n,vector<vector<int>>&edges,int src,int dst,int target) {
        unordered_map<int,vector<pair<int,int>>>mpp;
        for(auto &vec:edges) {
            int u=vec[0],v=vec[1],w=vec[2];
            if(w==-1) continue;
            mpp[u].push_back({v,w});
            mpp[v].push_back({u,w});
        }
        bool flag=0;
        int res=dijkstra(src,dst,mpp,n);
        if(res<target){
            return {};
        }
        else if(res==target){
            for(auto &vec:edges){
                if(vec[2]==-1){
                    vec[2]=2e9;
                }
            }
            return edges;
        }
        else{
            for(auto &vec:edges){
                int u=vec[0],v=vec[1],w=vec[2];
                if(w!=-1) continue;
                vec[2]=1;
                if(flag){
                    vec[2]=2e9;
                    continue;
                }
                mpp[u].push_back({v,1});
                mpp[v].push_back({u,1});

                int dist=dijkstra(src,dst,mpp,n);
                if(dist<=target){
                    int diff=target-dist;
                    vec[2]+=diff;
                    flag=1;
                }
            }
        }

        if(!flag) return {};
        return edges;
    }
};
