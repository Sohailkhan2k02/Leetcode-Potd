//T.C : O(n+q⋅logn)
//S.C : O(4n+logn)=O(n)
class Solution {
public:

    bool construct(vector<int>& nums, int l, int r, bool st[], int ind) {
        if(l==r) {
            st[ind]=true;
            return st[ind];
        }

        int m = (l+r)/2;

        bool b1 = construct(nums,l,m,st,2*ind+1);
        bool b2 = construct(nums,m+1,r,st,2*ind+2);

        return st[ind] = b1 && b2 && (nums[m]%2 + nums[m+1]%2 == 1);
    }

    bool find(vector<int>& nums, int l, int r, bool st[], int ind, int x, int y) {

        if(r<x || l>y)
            return true;
        
        if(x<=l && r<=y)
            return st[ind];
        
        int m = (l+r)/2;
        bool b1 = find(nums,l,m,st,2*ind+1,x,y);
        bool b2 = find(nums,m+1,r,st,2*ind+2,x,y);

        if(m>=x && m<y)
            return b1 && b2 && (nums[m]%2 + nums[m+1]%2 == 1);
        
        return b1 && b2;
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n=nums.size();
        bool st[4*n];

        construct(nums,0,n-1,st,0);

        vector<bool>ans;

        for(int i=0; i<queries.size(); i++) {
            int x = queries[i][0];
            int y = queries[i][1];

            ans.push_back(find(nums,0,n-1,st,0,x,y));
        }

        return ans;
    }
};
