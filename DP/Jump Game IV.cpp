class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1) {
            return 0;
        }

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        unordered_set<int> visited;

        q.push(0);
        visited.insert(0);

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int i = q.front();
                q.pop();

                if (i == n - 1) {
                    return steps;
                }

                for (int nxt : mp[arr[i]]) {

                    if (!visited.count(nxt)) {
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }

                mp.erase(arr[i]);

                if (i - 1 >= 0 && !visited.count(i - 1)) {
                    visited.insert(i - 1);
                    q.push(i - 1);
                }

                if (i + 1 < n && !visited.count(i + 1)) {
                    visited.insert(i + 1);
                    q.push(i + 1);
                }
            }

            steps++;
        }

        return -1;
    }
};
