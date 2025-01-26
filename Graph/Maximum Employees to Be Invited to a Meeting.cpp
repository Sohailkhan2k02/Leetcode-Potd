//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int bfs(int& i, unordered_map<int, int> &vis, vector<vector<int>>& adj) {
        int mx = 1;
        queue<pair<int,int>>q;
        q.push({i, 1});
        while(!q.empty()){
            auto [i, d] = q.front();
            q.pop();
            for (auto &j : adj[i]) {
                if (!vis[j]) {
                    vis[j] = 1;
                    mx = max(mx, d+1);
                    q.push({j, d+1});
                }
            }
        }
        return mx;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            adj[favorite[i]].push_back(i);
        }
        vector<int> vis(n, 0);
        int mxLargeGroup = 0; // group with cycle > 2
        int chainOfGroups = 0; // sum of groups with cycle <= 2
        unordered_map<int, int>tmpVis;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            unordered_map<int, int> curDist;
            int node = i;
            int d = 0;
            while (!vis[node]) {
                vis[node] = 1;
                d++;
                curDist[node] = d;
                int nxt = favorite[node];
                if (curDist.count(nxt)) {
                    int len = d - curDist[nxt] + 1; 
                    tmpVis[node]=1;
                    tmpVis[nxt]=1;
                    if (len == 2) {
                        int mxL = 0, mxR = 0;
                        for (auto& x : adj[node]) {
                            if (x != nxt) {
                                mxL = max(mxL, bfs(x, tmpVis, adj));
                            }
                        }
                        for (auto& x : adj[nxt]) {
                            if (x != node) {
                               mxR = max(mxR, bfs(x, tmpVis, adj));
                            }
                        }
                        chainOfGroups += mxL + mxR + 2;
                    } else {
                        mxLargeGroup = max(mxLargeGroup, len);
                    }
                    break;
                }
                node = nxt;
            }
        }
        return max(mxLargeGroup, chainOfGroups);
    }
};
