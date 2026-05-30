struct Seg{
    vector<int> tree;
    Seg(int n){
        tree = vector<int>(4*(n+1),0);
    }
    void update(int i,int st,int end,int idx,int val){
        if(st == end){
            tree[i] = val;
            return;
        }
        int mid = (st+end)/2;
        if(idx <= mid) update(2*i+1,st,mid,idx,val);
        else update(2*i+2,mid+1,end,idx,val);
        tree[i] = max(tree[2*i+1],tree[2*i+2]);
    }
    int query(int i,int st,int end,int l,int r){
        if(r < st || l > end) return 0;
        if(st >= l && end <= r) return tree[i];
        int mid = (st+end)/2;
        return max(query(2*i+1,st,mid,l,r),query(2*i+2,mid+1,end,l,r));
    }
};
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& q) {
        int n = 0;
        vector<bool> ans;
        for(auto& x : q) n = max(n,x[1]);
        Seg s(n);
        set<int> a = {0,n+1};
        for(auto& x : q){
            if(x[0] == 1){
                int y = x[1];
                auto it = a.lower_bound(y);
                int next = *it;
                it--;
                int prev = *it;
                s.update(0,0,n,y,y-prev);
                a.insert(y);
                if (next <= n) {
                    s.update(0, 0, n, next, next - y);
                }
            }else{
                int y = x[1];
                int sz = x[2];
                int best = s.query(0,0,n,0,y);
                auto it = a.upper_bound(y);
                it--;
                best = max(best,y-*it);
                if(best >= sz) ans.push_back(true);
                else ans.push_back(false);
            }
        }
        return ans;
    }
};
