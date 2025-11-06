class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int i){
            while (parent[i] != i){
                parent[i] = parent[parent[i]];
                i = parent[i];
            }
            return i;
        };
        for (auto& connect : connections){
            int u = connect[0], v = connect[1];
            int ui = find(u), vi = find(v);
            if (ui != vi)
                parent[vi] = ui;
        }
        vector<int> next_node(c + 1, 0), comp_min(c + 1, 0), last(c + 1, 0);
        for (int i = 1; i <= c; i++){
            int r = find(i);
            if (comp_min[r] == 0)
                comp_min[r] = i;
            else
                next_node[last[r]] = i;
            last[r] = i;
        }
        vector<bool> offline(c + 1, false);
        vector<int> res;
        for (auto& q : queries){
            int t = q[0], x = q[1];
            if (t == 1){
                if (!offline[x]){
                    res.push_back(x);
                } else {
                    int r = find(x);
                    int m = comp_min[r];
                    res.push_back(m ? m : -1);
                }
            } else {
                if (offline[x])
                    continue;
                offline[x] = true;
                int r = find(x);
                if (comp_min[r] == x){
                    int y = next_node[x];
                    while (y && offline[y])
                        y = next_node[y];
                    comp_min[r] = y;
                }
            }
        }
        return res;

    }
};
