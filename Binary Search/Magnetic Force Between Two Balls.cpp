//T.C : O(nlogn + n*log(max_force_diff))
//S.C : O(1)
class Solution {
public:
    int n;
    bool f(int mini, vector<int>& position, int m) {
        int last = position[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (position[i] - last >= mini) {
                cnt++;
                last = position[i];
                if (cnt == m) {
                    return true;
                }
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        n = position.size();
        sort(position.begin(), position.end());
        int l = 1, h = position[n-1] - position[0];
        while (l < h) {
            int mid = l + (h - l + 1) / 2;
            if (f(mid, position, m)) {
                l = mid;
            } else {
                h = mid - 1;
            }
        }
        return l;
    }
};
