class SegmentTree {
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(idx, val, 2 * node + 1, start, mid);
            else
                update(idx, val, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
 
    int query(int l, int r, int node, int start, int end) {
        if (l > end || r < start) {
            return 0; // No overlap
        }
        if (l <= start && end <= r) {
            return tree[node]; // Total overlap
        }
        int mid = (start + end) / 2;
        int leftSum = query(l, r, 2 * node + 1, start, mid);
        int rightSum = query(l, r, 2 * node + 2, mid + 1, end);
        return leftSum + rightSum; // Partial overlap
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, n - 1);
    }

    int query(int l, int r) {
        if(l > r) return 0;
        return query(l, r, 0, 0, n - 1);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        int idx = 1;

        for (auto& x : nums1) mpp[x] = idx++;
        for (auto& i : nums2) i = mpp[i];

        vector<int> leftArr(nums1.size(), 0), rightArr(nums1.size(), 1);
        SegmentTree leftTree(leftArr), rightTree(rightArr);

        leftTree.update(nums2[0] - 1, 1);
        rightTree.update(nums2[0] - 1, 0);

        long long total = 0;
        for (int i = 1; i < nums1.size() - 1; i++) {
            int idx = nums2[i];
            rightTree.update(idx - 1, 0);
            int left = leftTree.query(0, idx - 2);
            int right = rightTree.query(idx, nums1.size() - 1);
            total += (long long)left * right;
            leftTree.update(idx - 1, 1);
        }
        return total;
    }
};
