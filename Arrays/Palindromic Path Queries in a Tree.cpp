
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, parent;
    vector<int> bit, nodeMask, basePrefix;

    int charMask(char c) {
        return 1 << (c - 'a');
    }

    // Fenwick Tree for range XOR updates and point queries
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    void rangeXor(int l, int r, int val) {
        add(l, val);
        if (r + 1 <= n) {
            add(r + 1, val);
        }
    }

    int pointQuery(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= bit[idx];
        }
        return res;
    }

    // Iterative DFS: safe for a chain of 50000 nodes
    void dfs(int root) {
        vector<int> iter(n, 0);
        vector<int> st;
        st.push_back(root);

        parent[root] = root;
        depth[root] = 0;
        basePrefix[root] = nodeMask[root];

        while (!st.empty()) {
            int u = st.back();

            if (iter[u] == 0) {
                tin[u] = ++timer;

                up[0][u] = parent[u];
                for (int j = 1; j < LOG; j++) {
                    up[j][u] = up[j - 1][up[j - 1][u]];
                }
            }

            if (iter[u] < (int)adj[u].size()) {
                int v = adj[u][iter[u]++];

                if (v == parent[u]) {
                    continue;
                }

                parent[v] = u;
                depth[v] = depth[u] + 1;

                // Initial root-to-node parity mask
                basePrefix[v] = basePrefix[u] ^ nodeMask[v];

                st.push_back(v);
            } else {
                tout[u] = timer;
                st.pop_back();
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[j][u];
            }
        }

        if (u == v) {
            return u;
        }

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return parent[u];
    }

    // Current root-to-node parity mask
    int getPrefix(int u) {
        return basePrefix[u] ^ pointQuery(tin[u]);
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        timer = 0;

        LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        adj.assign(n, {});

        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        parent.resize(n);
        nodeMask.resize(n);
        basePrefix.resize(n);

        up.assign(LOG, vector<int>(n));
        bit.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            nodeMask[i] = charMask(s[i]);
        }

        dfs(0);

        vector<bool> ans;
        ans.reserve(queries.size());

        for (const string& q : queries) {
            string type;
            int u;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = charMask(c);
                int delta = nodeMask[u] ^ newMask;

                if (delta != 0) {
                    // Changing u affects the prefix mask of
                    // every node in u's subtree.
                    rangeXor(tin[u], tout[u], delta);
                    nodeMask[u] = newMask;
                }
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int pathMask =
                    getPrefix(u) ^
                    getPrefix(v) ^
                    nodeMask[w];

                // At most one character has odd frequency
                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};
