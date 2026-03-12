class Solution {
public:
struct DSU {
	vector<int> e; DSU(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { 
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU d(n+2);
        multiset<int>s;
        vector<vector<int>>can;
        for(auto &x : edges) {
            if(x[3]) {
                s.insert(x[2]);
                if(!d.unite(x[0],x[1])) {
                    return -1;
                }
                d.unite(x[0],x[1]);
            } else {
                can.push_back({x[2],x[0],x[1]});
            }
        }
        sort(can.rbegin(),can.rend());
        multiset<int>updated;
        for(auto &x : can) {
            if(d.size(0) == n) {
                break;
            }
            if(d.unite(x[1],x[2])) {
                // update this
                if(k > 0) {
                    if(s.empty() || (*s.begin() > x[0])) {
                     k--;
                     updated.insert(x[0]*2);
                     s.insert(x[0]*2);
                    }
                } else {
                    // can i use a before one.
                    if((int)updated.size() > 0) {
                        int mx = *updated.rbegin();
                        s.erase(s.find(mx));
                        updated.erase(updated.find(mx));
                        mx/=2;
                        s.insert(mx);
                        updated.insert(x[0]*2);
                        s.insert(x[0]*2);
                    } else {
                        s.insert(x[0]);
                    }
                }
            }
        }
        if(d.size(0) != n) {
            return -1;
        }
        return *s.begin();
    }
};
