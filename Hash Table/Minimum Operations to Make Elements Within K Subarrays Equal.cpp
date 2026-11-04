struct DualHeap {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    unordered_map<int, int> delayed;
    int leftSize = 0, rightSize = 0;
    long long sumL = 0, sumR = 0;

    template <typename Heap>
    void prune(Heap& heap) {
        while (!heap.empty()) {
            if (delayed[heap.top()]) {
                delayed[heap.top()]--;
                heap.pop();
            } else {
                break;
            }
        }
    }

    void balance() {
        if (leftSize > rightSize + 1) {
            int num = left.top();
            right.push(num);
            sumR += num;
            sumL -= num;
            left.pop();
            rightSize++;
            leftSize--;
            prune(left);
        } else if (rightSize > leftSize) {
            int num = right.top();
            left.push(num);
            sumL += num;
            sumR -= num;
            right.pop();
            leftSize++;
            rightSize--;
            prune(right);
        }
    }

    void add(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
            leftSize++;
            sumL += num;
        } else {
            right.push(num);
            rightSize++;
            sumR += num;
        }
        balance();
    }

    void remove(int num) {
        if (num <= left.top()) {
            leftSize--;
            delayed[num]++;
            sumL -= num;
            if (num == left.top()) {
                prune(left);
            }
        } else {
            rightSize--;
            ++delayed[num];
            sumR -= num;
            if (num == right.top()) {
                prune(right);
            }
        }
        balance();
    }

    long long getCost() {
        long long mid = left.top();
        return sumR - sumL + mid * (leftSize - rightSize);
    }
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        DualHeap dh;
        vector<long long> ops(n);

        for (int i = 0; i < n; i++) {
            dh.add(nums[i]);
            if (i >= x) {
                dh.remove(nums[i - x]);
            }
            if (i >= x - 1) {
                ops[i] = dh.getCost();
            }
        }

        const long long INF = 1e18;
        vector<vector<long long>> dp(n, vector<long long>(k + 1, INF));

        for (int i = x - 1; i < n; i++) {
            int max_j = min(k, (i + 1) / x);

            for (int j = 1; j <= max_j; j++) {
                // Option 1: Skip nums[i]
                long long best = (i > 0) ? dp[i - 1][j] : INF;

                // Option 2: Form a subarray ending at nums[i] (covers [i - x + 1 ... i])
                long long prev_cost = (j == 1) ? 0 : dp[i - x][j - 1];
                if (prev_cost != INF) {
                    best = min(best, prev_cost + ops[i]);
                }

                dp[i][j] = best;
            }
        }

        return dp[n - 1][k];
    }
};
