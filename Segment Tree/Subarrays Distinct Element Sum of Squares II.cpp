class Solution {
    static constexpr int kMod = 1E9 + 7;
    static constexpr int kLeftBoundary = -1;
public:
    int sumCounts(vector<int>& nums) {
        const int max_val = *std::max_element(nums.begin(), nums.end());
        std::vector<int> val_to_latest_idx(max_val + 1, kLeftBoundary);
        Integer result = 0;
        RangeSumQuery range_linear_sum_query(nums.size());
        Integer subarr_square_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            const int val = nums[i];
            const int j = val_to_latest_idx[val];
            // All subarrays [t, i] where t > j have one more unique value.
            const Integer delta_len = i - j;
            if (j + 1 <= i - 1) {
                // (x + 1) * (x + 1) - x * x == 2 * x + 1
                subarr_square_sum += 
                    range_linear_sum_query.get(j + 1, i - 1) * 2 +
                    + (i - 1 - (j + 1) + 1); 
            }
            subarr_square_sum += 1;            
            result += subarr_square_sum;

            range_linear_sum_query.update(j + 1, i, 1);
            val_to_latest_idx[val] = i;
        }
        return result.value();
    }
private:
    class Integer {
    public:
        Integer(int val) : val_(val) {}
        int value() const {
            return val_;
        }
        Integer operator+=(const Integer &rhs) {
            return val_ = (val_ + rhs.val_) % kMod;
        }
        Integer operator+(const Integer &rhs) const {
            return (val_ + rhs.val_) % kMod;
        }
        Integer operator-(const Integer &rhs) const {
            return (val_ + kMod - rhs.val_) % kMod;
        }
        Integer operator*(const Integer &rhs) const {
            return (val_ * rhs.val_) % kMod;
        }
        Integer operator/(const Integer &rhs) const {
            return (val_ / rhs.val_) % kMod;
        }
    private:
        int val_;
    };

    class RangeSumQuery {
    public:
        RangeSumQuery(const int n) : n(n) {
            tree.resize(4 * n, 0);
            lazy.resize(4 * n, 0);
        }
        
        void update(int left, int right, Integer value) {
            update_tree(0, 0, n - 1, left, right, value);
        }
        
        Integer get(int left, int right) {
            return query_tree(0, 0, n - 1, left, right);
        }
        
    private:
        vector<Integer> tree;
        vector<Integer> lazy;
        int n;
        
        void build_tree(vector<int>& nums, int tree_index, int l, int r) {
            if (l == r) {
                tree[tree_index] = nums[l];
                return;
            }
            int mid = l + (r - l) / 2;
            build_tree(nums, 2 * tree_index + 1, l, mid);
            build_tree(nums, 2 * tree_index + 2, mid + 1, r);
            tree[tree_index] = tree[2 * tree_index + 1] + tree[2 * tree_index + 2];
        }
        
        void update_tree(
            int tree_index, int l, int r, int left, int right, Integer value) {
            // Handle lazy propagation
            if (lazy[tree_index].value() != 0) {
                tree[tree_index] += lazy[tree_index] * (r - l + 1);
                if (l != r) {  // Not a leaf node
                    lazy[2 * tree_index + 1] += lazy[tree_index];
                    lazy[2 * tree_index + 2] += lazy[tree_index];
                }
                lazy[tree_index] = 0;  // Reset the lazy value
            }
            
            if (r < left || l > right) return;  // Out of range
            
            if (l >= left && r <= right) {
                // Segment is fully within the range
                tree[tree_index] += value * (r - l + 1);
                if (l != r) {  // Not a leaf node
                    lazy[2 * tree_index + 1] += value;
                    lazy[2 * tree_index + 2] += value;
                }
                return;
            }
            
            // Partial overlap
            int mid = l + (r - l) / 2;
            update_tree(2 * tree_index + 1, l, mid, left, right, value);
            update_tree(2 * tree_index + 2, mid + 1, r, left, right, value);
            tree[tree_index] = tree[2 * tree_index + 1] + tree[2 * tree_index + 2];
        }
        
        Integer query_tree(int tree_index, int l, int r, int left, int right) {
            // Handle lazy propagation
            if (lazy[tree_index].value() != 0) {
                tree[tree_index] += lazy[tree_index] * (r - l + 1);
                if (l != r) {  // Not a leaf node
                    lazy[2 * tree_index + 1] += lazy[tree_index];
                    lazy[2 * tree_index + 2] += lazy[tree_index];
                }
                lazy[tree_index] = 0;  // Reset the lazy value
            }
            
            // Out of range
            if (r < left || l > right) return 0;
            
            // Segment is fully within the range
            if (l >= left && r <= right) return tree[tree_index];  
            
            // Partial overlap
            const int mid = l + (r - l) / 2;
            return 
                query_tree(2 * tree_index + 1, l, mid, left, right) +
                query_tree(2 * tree_index + 2, mid + 1, r, left, right);
        }
    };


};
