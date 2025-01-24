//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        unordered_map<int,vector<int>>mpp;
        vector<int>outdegree(n,0);
        for(int u=0; u<n; u++){
            for(auto v:graph[u]){
                mpp[v].push_back(u);
                outdegree[u]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }

        vector<int>res;
        while(!q.empty()){
            int node=q.front(); q.pop();
            res.push_back(node);

            for(auto vec:mpp[node]){
                outdegree[vec]--;
                if(outdegree[vec]==0){
                    q.push(vec);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
