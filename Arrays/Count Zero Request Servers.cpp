class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int logSize = logs.size();
        vector<int> ans(queries.size(), -1);
        vector<pair<int, int>> newLogs, newQueries;

        for (auto log : logs) { // sort as the time info
            newLogs.emplace_back(log[1], log[0]); // [time, id]
        }

        for (int i = 0 ; i < queries.size() ; ++i ) { // sort the queries time and keep the order
            newQueries.emplace_back(queries[i], i);
        }

        sort(newLogs.begin(), newLogs.end());
        sort(newQueries.begin(), newQueries.end());
        int left = 0, right = 0;

        int count = 0;
        vector<int> server(n + 1, 0);

        for (auto [querie, idx] : newQueries) { // just sliding window, and track the count in the interval
            while (right < logSize && newLogs[right].first <= querie) {
                server[newLogs[right].second]++;
                if (server[newLogs[right].second] == 1) count++;
                right++;
            }

            while (left < logSize && newLogs[left].first < querie - x) {
                server[newLogs[left].second]--;
                if (server[newLogs[left].second] == 0) count--;
                left++;
            }

            ans[idx] = n - count;
        }

        return ans;
    }
};
