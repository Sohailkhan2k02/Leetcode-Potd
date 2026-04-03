class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        vector<pair<int,int>> robo;
        for (int i = 0; i < (int)robots.size(); ++i) {
            robo.push_back({robots[i], distance[i]});
        }
        sort(robo.begin(), robo.end());
        int n = robots.size();
        vector<pair<int,int>> leftrange, rightrange;
        for (int i = 0; i < n; ++i) {
            int robot = robo[i].first;
            int d = robo[i].second;
            int left = max((i > 0 ? robo[i - 1].first + 1 : INT_MIN), robot - d);
            int right = min((i < n - 1 ? robo[i + 1].first - 1 : INT_MAX), robot + d);
            leftrange.push_back({left, robot});
            rightrange.push_back({robot, right});
        }
        sort(walls.begin(), walls.end());
        struct Key {
            int i, choice, wallIdx;
            bool operator==(const Key& o) const {
                return i == o.i && choice == o.choice && wallIdx == o.wallIdx;
            }
        };
        struct Hash {
            size_t operator()(const Key& k) const {
                return ((size_t)k.i * 1315423911u) ^ ((size_t)k.choice << 20) ^ (size_t)k.wallIdx;
            }
        };
        unordered_map<Key,int,Hash> memo;
        auto dp = [&](auto&& self, int i, int choice, int wallIdx) -> int {
            if (i == n) return 0;
            Key state{i,choice,wallIdx};
            if (memo.count(state)) return memo[state];
            pair<int,int> cur = (choice == 0 ? leftrange[i] : rightrange[i]);
            int j = wallIdx, cnt = 0;
            while (j < (int)walls.size() && walls[j] <= cur.second) {
                if (walls[j] >= cur.first) cnt++;
                j++;
            }
            int bestNext = 0;
            if (i+1 < n) {
                bestNext = max(self(self, i+1, 0, j), self(self, i+1, 1, j));
            }
            return memo[state] = cnt + bestNext;
        };

        return max(dp(dp, 0, 0, 0), dp(dp, 0, 1, 0));
    }
};
