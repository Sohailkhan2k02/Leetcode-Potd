using ll = long long;
using vi = vector<int>;

struct Node{
    int val,idx;
    Node():val(-1),idx(-1){}
    Node(int m,int id):val(m),idx(id){}
};

struct SegTree{
    int n;
    vector<Node> tree;
    SegTree(vi& fruits):n(fruits.size()), tree(fruits.size()*4) {build(0,n-1,0,fruits);}

    Node combine(int pos){
        Node a = tree[2*pos+1], b = tree[2*pos+2];
        if (a.val>b.val) return a;
        else if (a.val<b.val) return b;
        else return Node(a.val,min(a.idx,b.idx));
    }

    void build(int low ,int high ,int pos, vi& input){
        if (low==high){
            tree[pos] =  Node(input[low],low);
            return;
        }
        int mid = low+(high-low)/2;
        build(low,mid,2*pos+1,input);
        build(mid+1,high,2*pos+2,input);
        tree[pos] = combine(pos);
    }

    Node query(int low ,int high, int pos, int x){ //must be at least x 
        if (low==high) {
            if (tree[pos].val<x) return Node();
            return tree[pos];
        }
        int mid = low + (high-low)/2;
        if (tree[2*pos+1].val>=x) return query(low,mid,2*pos+1,x);
        else if (tree[2*pos+2].val>=x) return query(mid+1,high,2*pos+2,x);
        else return Node(); 
    }

    void update(int low ,int high, int pos, int id, int val){
        if (low==high){
            tree[pos].val = val;
            return;
        }
        int mid  = low+(high-low)/2;
        if (id<=mid) update(low,mid,2*pos+1,id,val);
        else update(mid+1,high,2*pos+2,id,val);
        tree[pos] = combine(pos);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegTree st (baskets);
        int res = 0, n = baskets.size();
        for (int f:fruits){
            Node evl = st.query(0,n-1,0,f);
            if (evl.val==-1) res ++;
            else st.update(0,n-1,0,evl.idx,-1);
        }
        return res;
    }
};
