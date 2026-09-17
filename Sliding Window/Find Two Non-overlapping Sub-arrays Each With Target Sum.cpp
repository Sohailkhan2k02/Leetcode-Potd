class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> prefsum(n, 0);
        prefsum[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefsum[i] = arr[i] + prefsum[i - 1];
        }

        vector<pair<int, int>> store;

        for (int i = 0; i < n; i++) {
            int prevsum = i == 0 ? 0 : prefsum[i - 1];

            int low = i;
            int high = n - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                int lastsum = prefsum[mid];
                int diff = lastsum - prevsum;

                if (diff >= target) {
                    high = mid - 1;

                    if (diff == target) {
                        store.push_back({i, mid});
                    }
                } else {
                    low = mid + 1;
                }
            }
        }

        if (store.size() <= 1) return -1;

        sort(store.begin(), store.end());

        vector<pair<int, int>> store2;
        store2.push_back(store[0]);

        for (int i = 1; i < store.size(); i++) {
            if (store[i].first != store[i - 1].first) {
                store2.push_back(store[i]);
            }
        }

        int ans = 1e9;
        int best = 1e9;
        int j = 0;

        for (int i = 0; i < store2.size(); i++) {
            while (j < i && store2[j].second < store2[i].first) {
                best = min(best, store2[j].second - store2[j].first + 1);
                j++;
            }

            if (best != 1e9) {
                int len = store2[i].second - store2[i].first + 1;
                ans = min(ans, best + len);
            }
        }

        return ans == 1e9 ? -1 : ans;
    }
};
