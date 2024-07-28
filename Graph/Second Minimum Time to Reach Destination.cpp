//T.C : O(E logV) - where E = number of edges and V = number of vertices
//S.C : O(V+E)
class Solution {
public:
    int mini=INT_MAX,smini=INT_MAX;
    void f(int &newtime,int d,int c){
        if((d/c)%2==1){
            newtime+=c-(d%c);
        }
    }
    void dijsktra(int src, int dst, unordered_map<int,vector<pair<int,int>>>&mpp, int change,int time, int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis1(n+1,INT_MAX);
        vector<int>dis2(n+1,INT_MAX);
        dis1[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            int newtime=d;
            f(newtime,d,change);
            newtime+=time;
            cout<<newtime<<" ";
            for(auto vec:mpp[node]){
                int adjnode=vec.first;
                int dist=vec.second;
                
                if(newtime<dis1[adjnode]){
                    dis2[adjnode]=dis1[adjnode];
                    dis1[adjnode]=newtime;
                    pq.push({newtime,adjnode});
                }
                else if(newtime>dis1[adjnode] && newtime<dis2[adjnode]){
                    dis2[adjnode]=newtime;
                    pq.push({newtime,adjnode});
                }
            }
        }
        mini=dis1[dst];
        smini=dis2[dst];
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<pair<int,int>>>mpp;
        for(auto vec:edges){
            int u=vec[0],v=vec[1];
            mpp[u].push_back({v,time});
            mpp[v].push_back({u,time});
        }

        dijsktra(1,n,mpp,change,time,n);
        return smini;
    }
};
