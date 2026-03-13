using ll = long long;
class Solution {
public:
    ll minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll l = -1;
        ll mw = *min_element(workerTimes.begin(), workerTimes.end());
        ll r = (mw * (1LL * mountainHeight * (mountainHeight + 1)) / 2) + 1;
        while (r - l > 1) {
            ll m = l + (r - l) / 2;
            ll tr = 0;
            for (auto &w : workerTimes) {
                ll t = (m * 2) / w;
                ll x = (sqrt(1.0 + 4.0 * t) - 1.0) / 2.0;
                while ((x + 1) * (x + 2) <= t) x++;
                while (x * (x + 1) > t) x--;
                tr += x;
                if (tr >= mountainHeight) break;
            }
            if (tr >= mountainHeight) r = m;
            else l = m;
        }
        return r;
    }
};
