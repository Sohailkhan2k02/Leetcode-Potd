#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <queue>
#include <stack>
#include <iomanip>
#include <array>
#include <functional>
#include <bitset>
using namespace std;

void baseIO(string s = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (s.size()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

int subcount = 32;

#define ll long long
#define db long double
#define all(x) (x).begin(), (x).end()

struct Info {

    int ans = 0;
    
    int pref = 0;
    int prefchar = -1;

    int suff = 0;
    int suffchar = -1;

    int sz = 0;

    Info() {

    }

    Info(int x) {
        ans = 1;
        
        pref = 1;
        prefchar = x;

        suff = 1;
        suffchar = x;

        sz = 1;
    }

    Info(int a, int b, int c, int d, int e, int f) {
        ans = a;

        pref = b;
        prefchar = c;

        suff = d;
        suffchar = e;

        sz = f;
    }
};

class Segtree {
public:
    int n;
    vector<Info> tree;
    Info neutral = Info();

    Info merge(const Info &a, const Info &b) {

        int nans = max(a.ans, b.ans);
        if (a.suffchar == b.prefchar) nans = max(nans, a.suff + b.pref);

        int npref = a.pref;
        if (a.pref == a.sz && a.prefchar == b.prefchar) npref = a.pref + b.pref;

        int nsuff = b.suff;
        if (b.suff == b.sz && b.prefchar == a.suffchar) nsuff = b.suff + a.suff;

        return {
            nans,
            npref,
            a.prefchar,
            nsuff,
            b.suffchar,
            a.sz + b.sz
        };
    }

    void init(int N) {
        n = N;
        tree.resize(4 * n);
    }

    template<typename T>
    void build(int C, int L, int R, const vector<T>& a) {
        if (L + 1 == R) {
            tree[C] = Info(a[L]);
            return;
        }

        int M = (L + R) / 2;
        build(2 * C, L, M, a);
        build(2 * C + 1, M, R, a);

        tree[C] = merge(tree[2 * C], tree[2 * C + 1]);
    }

    void update(int C, int L, int R, int i, const Info &v) {
        if (i < L || i >= R) return;
        if (L + 1 == R) {
            tree[C] = v;
            return;
        }

        int M = (L + R) / 2;
        update(2 * C, L, M, i, v);
        update(2 * C + 1, M, R, i, v);

        tree[C] = merge(tree[2 * C], tree[2 * C + 1]);
    }

    Info query(int C, int L, int R, int l, int r) {
        if (l <= L && R <= r) return tree[C];
        if (l >= R || L >= r) return neutral;

        int M = (L + R) / 2;
        return merge(query(2 * C, L, M, l, r), query(2 * C + 1, M, R, l, r));
    }

    template<typename T>
    void build(const vector<T>& a) {
        build(1, 0, n, a);
    }

    void update(int i, const Info &v) {
        update(1, 0, n, i, v);
    }

    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - 'a';
        }

        Segtree seg;
        seg.init(n);
        seg.build(a);

        vector<int> res;
        for (int i = 0; i < queryCharacters.size(); i++) {
            seg.update(queryIndices[i], queryCharacters[i] - 'a');
            res.push_back(seg.query(0, n).ans);
        }

        return res;
    }
};
