struct State {
    int product = -1;
    array<int, 5> v;
    State(int product): product(product){
        v.fill(0);
        v[product] = 1;
    }
    State(){
        v.fill(0);
    }
};
const int limit = 1e5 + 1;
const int mxStatesTree = 4 * limit + 1;
array<State, mxStatesTree> tree;
class SegmentTree {
public:
    int n, k;
    SegmentTree(vector<int> &nums, int &k): k(k){
        n = nums.size();
        // fill(tree.begin(), tree.begin() + 4 * n + 1, State());
        build(0, 0, n - 1, nums);
    }
    void helper(State& left, State& right, State &res){
        int leftproduct = left.product, product = (leftproduct * right.product) % k;
        res.v = left.v;
        res.product = product;
        for (int i = 0; i < k; i++){
            if (right.v[i] == 0){
                continue;
            }
            res.v[(leftproduct * i) % k] += right.v[i];
        }
    }
    void build(int node, int l, int r, vector<int> &nums){
        if (l == r){
            tree[node].v.fill(0);
            tree[node].product = nums[l];
            tree[node].v[nums[l]] = 1;
            return;
        }
        int mid = (l + r) / 2, leftNode = 2 * node + 1, rightNode = 2 * node + 2;
        build(leftNode, l, mid, nums);
        build(rightNode, mid + 1, r, nums);
        
        // int leftproduct = tree[leftNode].product, product = (leftproduct * tree[rightNode].product) % k;
        // vector<int> v = tree[leftNode].v;
        // for (int i = 0; i < k; i++){
        //     if (tree[rightNode].v[i] == 0){
        //         continue;
        //     }
        //     v[(leftproduct * i) % k] += tree[rightNode].v[i];
        // }
        // tree[node] = State(product, v);
        helper(tree[leftNode], tree[rightNode], tree[node]);
    }
    State _query(int node, int l, int r, int ql, int qr){
        if (l > qr || r < ql){
            return State();
        }
        if (l >= ql && r <= qr){
            return tree[node];
        }
        int mid = (l + r) / 2;
        State left = _query(node * 2 + 1, l, mid, ql, qr);
        State right = _query(node * 2 + 2, mid + 1, r, ql, qr);
        if (left.product != -1 && right.product != -1){
            State res;
            helper(left, right, res);
            return res;
        }
        else {
            return left.product != -1? left: right;
        }
    }
    int query(int ql, int qr, int a){
        State res = _query(0, 0, n - 1, ql, qr);
        return res.v[a];
    }
    void _update(int node, int l, int r, int idx, int val){
        if (l == r){
            tree[node] = State(val);
            return;
        }
        int mid = (l + r) / 2, leftNode = 2 * node + 1, rightNode = 2 * node + 2;
        if (idx <= mid){
            _update(leftNode, l, mid, idx, val);
        }
        else {
            _update(rightNode, mid + 1, r, idx, val);
        }
        helper(tree[leftNode], tree[rightNode], tree[node]);
    }
    void update(int idx, int val){
        _update(0, 0, n - 1, idx, val);
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size(), sz = queries.size();
        for (int i = 0; i < n; i++){
            nums[i] %= k;
        }
        SegmentTree sg(nums, k);
        vector<int> ans(sz);
        for (int i = 0; i < sz; i++){
            int idx = queries[i][0], val = queries[i][1], start = queries[i][2], x = queries[i][3];
            val %= k;
            int a = x % k;
            sg.update(idx, val);
            ans[i] = sg.query(start, n - 1, a);
        }
        return ans;
    }
};
