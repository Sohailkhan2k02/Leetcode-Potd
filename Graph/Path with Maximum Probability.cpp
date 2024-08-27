//T.C : O((v+e)log(v))
//S.C : O((v+e))
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int s, int e) {
        unordered_map<int,vector<pair<int,double>>>mpp;
        // THIS WAS CAUSING RUNTIME ERROR FUCK THIS TOOK ME WHOLE DAY
        // F**K THIS SHIT
        // for(vector<int>&vec:edges){
        //     int u=vec[0];
        //     int v=vec[1];
        //     double p=vec[2];

        //     mpp[u].push_back({v,p});
        //     mpp[v].push_back({u,p});
        // }

        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succProb[i];
            mpp[u].push_back({v,p});
            mpp[v].push_back({u,p});
        }
        vector<double>res(n,0);
        priority_queue<pair<double,int>>pq; // MAX HEAP BECAUSE WE NEED MAX PROBABILITY
        pq.push({1.0,s});
        res[s]=1;
        
        while(!pq.empty()){
            double d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &vec:mpp[node]){
                int adjNode=vec.first;
                double dist=vec.second;
                if(d*dist>res[adjNode]){
                    res[adjNode]=d*dist;
                    pq.push({d*dist,adjNode});
                }
            }
        }
        return res[e];
    }
};
