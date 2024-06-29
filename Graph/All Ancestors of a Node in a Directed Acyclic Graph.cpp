//T.C : O(v*log(e)+v+vlog(e))
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mpp;
        vector<int> indegree(n, 0);
        
        for (auto& vec : edges) {
            int u = vec[0], v = vec[1];
            mpp[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<set<int>> st(n);
        vector<int> topo;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            
            for (auto v : mpp[u]) {
                indegree[v]--;
                st[v].insert(u);
                if (indegree[v] == 0) {
                    q.push(v);
                }
                for (auto ancestor : st[u]) {
                    st[v].insert(ancestor);
                }
            }
        }
        
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = vector<int>(st[i].begin(), st[i].end());
        }
        
        return res;
    }
};
