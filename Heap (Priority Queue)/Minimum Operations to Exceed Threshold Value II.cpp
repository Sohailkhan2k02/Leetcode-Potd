//T.C : O(nlogk)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
    priority_queue<long long, vector<long long>, greater<long long>> q;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        q.push(nums[i]);
    }
    while (q.size() > 1) {
        long long ptr = q.top(); q.pop();
        long long qtr = q.top(); q.pop();

        if (ptr >= k) break;

        long long wqw = (ptr * 2LL) + qtr;
        q.push(wqw);
        ++cnt;
    }

    return cnt;
    }
};
