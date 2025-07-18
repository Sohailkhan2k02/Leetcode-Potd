class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size(), k = n / 3;

        vector<long long> leftSums(k + 1);
        priority_queue<int> maxHeap;
        long long leftSum = 0;

        for (int i = 0; i < k; ++i) {
            maxHeap.push(nums[i]);
            leftSum += nums[i];
        }
        leftSums[0] = leftSum;

        for (int i = k; i < 2 * k; ++i) {
            if (nums[i] < maxHeap.top()) {
                // isse acha uss chotu ko lelete
                leftSum += nums[i] - maxHeap.top();
                maxHeap.pop();
                maxHeap.push(nums[i]);
            }
            leftSums[i - k + 1] = leftSum;
        }

        vector<long long> rightSums(k + 1);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long rightSum = 0;

        for (int i = n - 1; i >= n - k; --i) {
            minHeap.push(nums[i]);
            rightSum += nums[i];
        }
        rightSums[k] = rightSum;

        for (int i = n - k - 1; i >= k; --i) {
            if (nums[i] > minHeap.top()) {
                // isse acha uss motu ko lelete
                rightSum += nums[i];
                rightSum -= minHeap.top();
                minHeap.pop();
                minHeap.push(nums[i]);
            }
            rightSums[i - k] = rightSum;
        }

        long long minDiff = LLONG_MAX;
        for (int i = 0; i <= k; ++i) {
            minDiff = min(minDiff, leftSums[i] - rightSums[i]);
        }

        return minDiff;
    }
};
