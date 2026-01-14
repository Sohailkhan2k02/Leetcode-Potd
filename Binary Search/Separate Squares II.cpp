class SegmentTree {
private:
    vector<int> cnt;
    vector<long long> covered;
    vector<long long> xs;
    int n;

    void pull(int pos, int l, int r) {
        if (cnt[pos] > 0) {
            covered[pos] = xs[r + 1] - xs[l];
        } else if (l == r) {
            covered[pos] = 0;
        } else {
            covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
        }
    }

    void update(int ql, int qr, int val, int l, int r, int pos) {
        if (xs[r + 1] <= ql || xs[l] >= qr) return;

        if (ql <= xs[l] && xs[r + 1] <= qr) {
            cnt[pos] += val;
            pull(pos, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(ql, qr, val, l, mid, pos * 2 + 1);
        update(ql, qr, val, mid + 1, r, pos * 2 + 2);
        pull(pos, l, r);
    }

public:
    SegmentTree(vector<long long>& xs_) : xs(xs_) {
        n = xs.size() - 1;
        cnt.assign(4 * n, 0);
        covered.assign(4 * n, 0);
    }

    void update(long long l, long long r, int val) {
        update(l, r, val, 0, n - 1, 0);
    }

    long long query() {
        return covered[0];
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<long long, int, long long, long long>> events;
        vector<long long> xs;

        for (auto& sq : squares) {
            long long x = sq[0], y = sq[1], l = sq[2];
            events.emplace_back(y, +1, x, x + l);
            events.emplace_back(y + l, -1, x, x + l);
            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(events.begin(), events.end());

        SegmentTree st(xs);

        struct Slab {
            long long y1, y2;
            long long width;
            long double areaBefore;
        };

        vector<Slab> slabs;

        long long prevY = get<0>(events[0]);
        long double area = 0.0;

        for (int i = 0; i < events.size();) {
            long long curY = get<0>(events[i]);
            long long dy = curY - prevY;
            long long width = st.query();

            if (dy > 0 && width > 0) {
                slabs.push_back({prevY, curY, width, area});
                area += (long double)width * dy;
            }

            while (i < events.size() && get<0>(events[i]) == curY) {
                auto [y, delta, xl, xr] = events[i];
                st.update(xl, xr, delta);
                i++;
            }

            prevY = curY;
        }

        long double target = area / 2.0;

        for (auto& s : slabs) {
            long double slabArea = (long double)s.width * (s.y2 - s.y1);
            if (s.areaBefore + slabArea >= target) {
                long double rem = target - s.areaBefore;
                return (double)(s.y1 + rem / s.width);
            }
        }

        return 0.0;
    }
};
