//T.C : O(n*2^n)
//S.C : O(n*2^n)
class Solution {
public:
    void f(int i,vector<int>&nums,vector<int>&ds, vector<vector<int>>&res,int maxi, int n){
        if(i==n){
            int a=0;
            for(auto i:ds){
                a|=i;
            }
            if(a==maxi){
                res.push_back(ds);
            }
            return;
        }

        ds.push_back(nums[i]);
        f(i+1,nums,ds,res,maxi,n);
        ds.pop_back();

        f(i+1,nums,ds,res,maxi,n);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int maxi=0;
        int a=nums[0];
        for(int i=1; i<n; i++){
            a|=nums[i];
            maxi=max(maxi,a);
        }
        cout<<maxi;
        vector<vector<int>>res;
        vector<int>ds;
        f(0,nums,ds,res,maxi,n);
        return res.size();
    }
};
