struct BIT {
private:
    inline static constexpr int nMx{100000};
    inline static int arr[nMx + 1];
    int n;
public:
    BIT(const int n) : n{n} {
        memset(arr, 0, sizeof(int) * (n + 1));
    }
    void upd(int i, int val) {
        for (++i; i <= n; i += i & -i) arr[i] += val;
    }
    int pre(int i) {
        int sum{0};
        for (++i; i > 0; i -= i & -i) sum += arr[i];
        return sum;
    }
    int qry(int l, int r) {
        return pre(r) - pre(l - 1);
    }
};

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        const int n{static_cast<int>(arrival.size())};
        BIT bit{k};
        static int cnt[100000];
        memset(cnt, 0, sizeof(int) * k);
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq{};
        auto gap{[&](int l, int r) -> bool {
            if (l <= r) return r - l + 1 - bit.qry(l, r) > 0;
            return r + k - l + 1 - bit.qry(l, k - 1) - bit.qry(0, r) > 0;
        }};
        int mx{0}, mxCnt{0};
        for (int i{0}; i < n; ++i) {
            const int t{arrival[i]}, len{load[i]};
            while (!pq.empty() && pq.top().first <= t) {
                bit.upd(pq.top().second, -1);
                pq.pop();
            }
            if (pq.size() == k) continue;
            const int want{i % k};
            int l{want}, r{(want - 1 + k) % k};
            while (l != r) {
                const int m{l < r ? (r + l) / 2 : ((r + k + l) / 2) % k};
                if (gap(want, m)) r = m;
                else l = (m + 1) % k;
            }
            if (++cnt[l] >= mx) {
                if (cnt[l] > mx) {
                    mx = cnt[l];
                    mxCnt = 0;
                }
                ++mxCnt;
            }
            bit.upd(l, 1);
            pq.emplace(t + len, l);
        }
        vector<int> res{};
        res.reserve(mxCnt);
        for (int i{0}; i < k; ++i) {
            if (cnt[i] == mx) res.push_back(i);
        }
        return res;
    }
};
