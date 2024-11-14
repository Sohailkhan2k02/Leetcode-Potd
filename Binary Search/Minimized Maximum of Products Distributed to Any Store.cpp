//T.C : O(mlog(10^5)
//S.C : O(1)
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& qty) {
        int m = qty.size();
		auto valid = [&](int &mx) {
			int st = 0;
			for (int &q: qty) {
				int s = ceil((1.0 * q) / mx);
				st += s;
			}
			return st <= n;
		};
		int lo = 1, hi = 1e5;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (valid(mid)) hi = mid;
			else lo = mid + 1;
		}
		return lo;
    }
};
