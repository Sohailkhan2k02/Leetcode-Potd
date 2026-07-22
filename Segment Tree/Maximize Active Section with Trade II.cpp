#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Group {
        int start;
        int len;
    };

    class SparseTable {
    public:
        vector<vector<int>> st;
        vector<int> lg;

        SparseTable() {}

        SparseTable(const vector<int>& nums) {
            int n = nums.size();
            if (n == 0)
                return;

            lg.resize(n + 1);
            for (int i = 2; i <= n; i++)
                lg[i] = lg[i / 2] + 1;

            st.assign(lg[n] + 1, vector<int>(n));
            st[0] = nums;

            for (int k = 1; k <= lg[n]; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        int query(int l, int r) {
            if (l > r)
                return 0;
            int k = lg[r - l + 1];
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        }
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {

        int ones = count(s.begin(), s.end(), '1');

        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex(s.size());

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '0') {
                if (i && s[i - 1] == '0')
                    zeroGroups.back().len++;
                else
                    zeroGroups.push_back({i, 1});
            }
            zeroGroupIndex[i] = (int)zeroGroups.size() - 1;
        }

        if (zeroGroups.empty())
            return vector<int>(queries.size(), ones);

        vector<int> mergeLen;
        for (int i = 0; i + 1 < (int)zeroGroups.size(); i++)
            mergeLen.push_back(zeroGroups[i].len + zeroGroups[i + 1].len);

        SparseTable st(mergeLen);

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int left = zeroGroupIndex[l] == -1
                           ? -1
                           : zeroGroups[zeroGroupIndex[l]].len -
                                 (l - zeroGroups[zeroGroupIndex[l]].start);

            int right = zeroGroupIndex[r] == -1
                            ? -1
                            : r - zeroGroups[zeroGroupIndex[r]].start + 1;

            int startAdj = zeroGroupIndex[l] + 1;
            int endAdj =
                (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1) - 1;

            int best = ones;

            if (s[l] == '0' && s[r] == '0' &&
                zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {

                best = max(best, ones + left + right);

            } else if (startAdj <= endAdj) {

                best = max(best, ones + st.query(startAdj, endAdj));
            }

            if (s[l] == '0' &&
                zeroGroupIndex[l] + 1 <=
                    (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1)) {

                best = max(best,
                           ones + left + zeroGroups[zeroGroupIndex[l] + 1].len);
            }

            if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {

                best = max(best, ones + right +
                                     zeroGroups[zeroGroupIndex[r] - 1].len);
            }

            ans.push_back(best);
        }

        return ans;
    }
};
