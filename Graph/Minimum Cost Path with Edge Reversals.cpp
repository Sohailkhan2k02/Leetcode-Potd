class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>graph(n);
        for(int i = 0;i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 2 * w});
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;
        pq.push({0, 0});
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;
        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : graph[node]){
                int nd = it.first;
                int wt = it.second;
                if(wt + weight < ans[nd]){
                    ans[nd] = wt + weight;
                    pq.push({ans[nd], nd});
                }
            }
        }
        return ans[n-1] == INT_MAX ? -1 : ans[n-1];
    }
};
