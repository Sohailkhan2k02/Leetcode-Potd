//T.C : O(n⋅(V+E)logV)
//S.C : O(n)+O(V)+O(V+E)+O(n)=O(V+E+n)
class Solution {
public:
    vector<pair<int,int>>count;
    void dijsktra(int i,unordered_map<int,vector<pair<int,int>>>&mpp, int distanceThreshold, int n){
        int u=i;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,i});
        vector<int>dis(n,INT_MAX);
        dis[i]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(d>distanceThreshold) continue;

            for(auto &vec:mpp[node]){
                int adjnode=vec.first,dist=vec.second;
                if(d+dist<dis[adjnode] && d+dist<=distanceThreshold){
                    dis[adjnode]=d+dist;
                    pq.push({d+dist,adjnode});
                }
            }
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            if(dis[i]!=INT_MAX && i!=u){
                cnt++;
            }
        }
        count.push_back({cnt,u});
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>>mpp;
        for(auto vec:edges){
            int u=vec[0],v=vec[1],wt=vec[2];
            mpp[u].push_back({v,wt});
            mpp[v].push_back({u,wt});
        }
        for(int i=0; i<n; i++){
            dijsktra(i,mpp,distanceThreshold,n);
        }

        auto lamda=[&](pair<int,int>a, pair<int,int>b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first<b.first;
        };
        sort(count.begin(),count.end(),lamda);
        for(auto i:count){
            cout<<i.second<<"->"<<i.first<<" ";
        }
        return count[0].second;
    }
};
