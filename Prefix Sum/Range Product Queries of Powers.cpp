class SegmentTree {
    vector<long long> tree;
    int size;
    const long long MOD = 1e9 + 7;

public:
    SegmentTree(int n) {
        tree.resize(4 * n);
        size = n;
    }

    void build(int ind, int low, int high, vector<int> &nums) {
        if (low == high) {
            tree[ind] = nums[low];
            return;
        }

        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, nums);
        build(2 * ind + 2, mid + 1, high, nums);

        tree[ind] = ( (1LL * tree[2 * ind + 1] % MOD) * (tree[2 * ind + 2] % MOD) ) % MOD;
    }

    long long query(int ind, int low, int high, int l, int r) {
        // no overlap
        if (r < low || high < l)
            return 1;

        // complete overlap
        if (l <= low && high <= r)
            return tree[ind];

        int mid = (low + high) >> 1;
        long long left = query(2 * ind + 1, low, mid, l, r);
        long long right = query(2 * ind + 2, mid + 1, high, l, r);

        return ( (1LL * left % MOD) * (right % MOD) ) % MOD;
    }
};

class Solution {
private:
    void findPower(int n, vector<int> &power) {
        int p = 0;
        while (n) {
            int bit = n & 1;
            int num = (1 << p) * bit;
            if (num)
                power.push_back(num);
            p++;
            n >>= 1;
        }
    }

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        findPower(n, power);

        int m = power.size();
        int sz = queries.size();

        SegmentTree st(m);
        st.build(0, 0, m - 1, power);

        vector<int> ans(sz);
        for (int i = 0; i < sz; i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            ans[i] = st.query(0, 0, m - 1, s, e);
        }
        return ans;
    }
};
