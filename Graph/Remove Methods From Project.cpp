class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> sus(n, 0);
        sus[k] = 1;

        // 1. Mark all methods reachable from k as suspicious
        queue<int> q;
        q.push(k);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (sus[v] == 0) {
                    sus[v] = 1;
                    q.push(v);
                }
            }
        }

        // 2. Check for a non-suspicious -> suspicious edge
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (sus[u] == 0 && sus[v] == 1) {
                // Cannot remove the suspicious group,
                // so return every method.
                vector<int> ans;

                for (int i = 0; i < n; i++)
                    ans.push_back(i);

                return ans;
            }
        }

        // 3. Otherwise return only non-suspicious methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (sus[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};
