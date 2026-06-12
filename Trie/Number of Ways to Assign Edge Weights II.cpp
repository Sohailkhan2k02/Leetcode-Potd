#include <vector>
#include <cmath>

using namespace std;

class Solution {
    vector<vector<int>> adj;     // Adjacency list to store tree
    vector<int> depth;           // Depth of each node from root
    vector<vector<int>> up;      // up[u][i] = 2^i-th ancestor of node u

    // DFS to calculate depth and binary lifting table
    void dfs(int node, int p, int d) {
        depth[node] = d;         // Store depth of current node
        up[node][0] = p;         // Direct parent of node

        // Build binary lifting table for current node
        for (int i = 1; i < 18; ++i) {
            if (up[node][i - 1] != -1)
                up[node][i] = up[up[node][i - 1]][i - 1];
            else
                up[node][i] = -1;
        }

        // Visit all children
        for (int child : adj[node]) {
            if (child != p) {
                dfs(child, node, d + 1);
            }
        }
    }

    // Find Lowest Common Ancestor of two nodes
    int getLCA(int u, int v) {

        // Make u the deeper node
        if (depth[u] < depth[v])
            swap(u, v);

        // Bring u to same depth as v
        for (int i = 17; i >= 0; --i) {
            if ((depth[u] - depth[v]) & (1 << i)) {
                u = up[u][i];
            }
        }

        // If both nodes become same, that is the LCA
        if (u == v)
            return u;

        // Move both nodes upward until their parents become same
        for (int i = 17; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        // Parent of both nodes is the LCA
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;
        int MOD = 1e9 + 7;

        // Initialize data structures
        adj.resize(n + 1);
        depth.resize(n + 1);

        // 18 because 2^18 > maximum possible node count
        up.assign(n + 1, vector<int>(18, -1));

        // Create tree using adjacency list
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Root tree at node 1
        dfs(1, -1, 0);

        // Precompute powers of 2
        // Used because answer = 2^(path length - 1)
        vector<int> pow2(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        // Process every query
        for (auto& q : queries) {

            int u = q[0];
            int v = q[1];

            // Same node means no edge in path
            if (u == v) {
                ans.push_back(0);
                continue;
            }

            // Find common ancestor
            int lca = getLCA(u, v);

            // Length of path between u and v
            int pathLength = depth[u] + depth[v] - 2 * depth[lca];

            // Number of ways to assign weights
            ans.push_back(pow2[pathLength - 1]);
        }

        return ans;
    }
};
