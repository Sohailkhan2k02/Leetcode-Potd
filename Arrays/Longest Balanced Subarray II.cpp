class Solution {
    int mn[400005], mx[400005], lz[400005], n;
    const int INF = 1e9;

    void app(int v, int val) {
        if (mn[v] < 1e8) { mn[v] += val; mx[v] += val; lz[v] += val; }
    }

    void psh(int v) {
        if (lz[v]) { app(2*v, lz[v]); app(2*v+1, lz[v]); lz[v] = 0; }
    }

    void act(int v, int tl, int tr, int p) {
        if (tl == tr) { mn[v] = mx[v] = lz[v] = 0; return; }
        psh(v);
        int tm = (tl + tr) / 2;
        if (p <= tm) act(2*v, tl, tm, p);
        else act(2*v+1, tm + 1, tr, p);
        mn[v] = min(mn[2*v], mn[2*v+1]);
        mx[v] = max(mx[2*v], mx[2*v+1]);
    }

    void upd(int v, int tl, int tr, int l, int r, int x) {
        if (l > r || mn[v] > 1e8) return;
        if (l == tl && r == tr) return app(v, x);
        psh(v);
        int tm = (tl + tr) / 2;
        upd(2*v, tl, tm, l, min(r, tm), x);
        upd(2*v+1, tm + 1, tr, max(l, tm + 1), r, x);
        mn[v] = min(mn[2*v], mn[2*v+1]);
        mx[v] = max(mx[2*v], mx[2*v+1]);
    }

    int fz(int v, int tl, int tr) {
        if (mn[v] > 1e8 || mn[v] > 0 || mx[v] < 0) return -1;
        if (tl == tr) return tl;
        psh(v);
        int tm = (tl + tr) / 2;
        int r = fz(2*v, tl, tm);
        return (r != -1) ? r : fz(2*v+1, tm + 1, tr);
    }

public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i <= 4 * n; ++i) { mn[i] = INF; mx[i] = -INF; lz[i] = 0; }
        unordered_map<int, int> pr;
        int ans = 0;
        for (int r = 0; r < n; ++r) {
            act(1, 0, n - 1, r);
            int v = nums[r], p = pr.count(v) ? pr[v] : -1;
            upd(1, 0, n - 1, p + 1, r, (v % 2 == 0 ? 1 : -1));
            int l = fz(1, 0, n - 1);
            if (l != -1) ans = max(ans, r - l + 1);
            pr[v] = r;
        }
        return ans;
    }
};
