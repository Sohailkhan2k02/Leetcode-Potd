class SegmentTree{
public:
    int n;
    vector<int> arr, tree;
    SegmentTree() {}
    SegmentTree(vector<int>& arr){
        n = arr.size();
        this->arr = arr;
        tree.resize(4*n);
        build(0,0,n-1);
    }

    void build(long long node, long long start, long long end){
        if(start == end){
            tree[node] = start;
            return;
        }

        long long mid = (start + end) / 2;

        build(2*node + 1, start, mid);
        build(2*node + 2, mid+1, end);

        long long left = tree[2*node+1];
        long long right = tree[2*node+2];

        tree[node] = (arr[left] > arr[right]) ? left : right;
    }

    long long query(long long node, long long start, long long end, long long l, long long r){
        if(r < start or l > end) return -1;
        if(l <= start and end <= r) return tree[node];

        long long mid = (start + end) / 2;
        long long left = query(2*node + 1, start, mid, l, r);
        long long right = query(2*node + 2, mid+1, end, l, r);

        if(left == -1) return right;
        if(right == -1) return left;
        return (arr[left] > arr[right]) ? left : right;
    }
};

class Custom{
private:

    long long n;
    vector<long long> pref, suff, arr;
    SegmentTree sg;

public:

    Custom(vector<int>& a){
        n = a.size();
        arr = vector<long long>(a.begin(),a.end());
        pref.resize(n);
        suff.resize(n);
        sg = SegmentTree(a);

        pref[0] = arr[0];
        for(int i=1; i<n; i++){
            pref[i] += arr[i] + pref[i-1];
        }

        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and arr[i] >= arr[st.top()]){
                st.pop();
            }

            if(st.empty()){
                suff[i] = arr[i] * (n-i);
            }
            else{
                suff[i] = suff[st.top()] + arr[i] * 1ll * (st.top() - i);
            }

            st.push(i);
        }
    }

    long long range(int l, int r){
        long long maxIdx = sg.query(0,0,n-1,l,r);

        long long totalOprations = suff[l] - suff[maxIdx] + (arr[maxIdx] * (r-maxIdx+1));
        long long prefSum = pref[r] - (l-1 >= 0 ? pref[l-1] : 0);

        return totalOprations - prefSum;
    }
};

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        Custom sol(nums);
        int n = nums.size();

        long long ans = 0;

        int i = 0, j = 0;

        while(j < n){
            while(i < j and sol.range(i,j) > k){
                i++;
            }

            ans += j-i+1;
            j++;
        }

        return ans;
    }
};
