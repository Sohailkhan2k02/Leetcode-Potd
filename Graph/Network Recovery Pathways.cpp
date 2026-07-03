#define ll long long

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int m=edges.size();
        int n=online.size();
        vector<vector<pair<ll,ll>>>adj(n);

        for(int i=0;i<m;i++){
            ll node1=edges[i][0];
            ll node2=edges[i][1];
            ll cost=edges[i][2];
            if(online[node1]==false || online[node2]==false) continue;
            adj[node1].push_back({node2,cost});
        }

        function<bool(ll)>chck=[&](ll mid){
            priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
            pq.push({0,0});
            vector<ll>vis(n,1e18);
            vis[0]=0;
            while(!pq.empty()){
                auto [maxvl,node]=pq.top();
                pq.pop();
                if(maxvl!=vis[node]) continue;
                for(auto &[node2,cost]:adj[node]){
                    if(cost+maxvl>k) continue;
                    if(cost<mid) continue;
                    if(vis[node2]>cost+maxvl){
                        vis[node2]=cost+maxvl;
                        pq.push({vis[node2],node2});
                    }
                }
            }
            return vis[n-1]<=k;
        };

        ll ans=-1;

        ll low=0,high=1e16;
        while(low<=high){
            ll mid=(low+high)/2;
            bool f1=chck(mid);
            if(f1){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }

        return ans;

    }
};
