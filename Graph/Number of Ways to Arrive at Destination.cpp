//T.C : O(e+v)logv
//S.C : O(e+v)
class Solution {
public:
    const int mod=1e9+7;
    typedef long long ll;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> mpp;
        for(auto vec: roads) {
            int u = vec[0];
            int v = vec[1];
            int t = vec[2];
            mpp[u].push_back({v,t});
            mpp[v].push_back({u,t});
        }

        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({0,0});
        vector<ll> dis(n, LONG_MAX);
        dis[0] = 0;
        vector<ll>cnt(n,0);
        cnt[0]=1;
        while(!pq.empty()){
            ll time=pq.top().first;
            ll node=pq.top().second;
            pq.pop();

            for(auto vec:mpp[node]){
                int adjnode=vec.first;
                int t=vec.second;
                if(t+time<dis[adjnode]){
                    dis[adjnode]=t+time;
                    pq.push({t+time,adjnode});
                    cnt[adjnode]=cnt[node];
                }
                else if(dis[adjnode]==t+time){
                    cnt[adjnode]=(cnt[adjnode]+cnt[node])%mod;
                }
            }
        }

        return cnt[n-1]%mod;
    }
};
