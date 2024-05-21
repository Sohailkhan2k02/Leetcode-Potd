class Solution {
public:
    // APPROACH -1 USING POWER SET BIT MANIPULATION
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        for(int num=0; num<(1<<n); num++){
            vector<int>sub;
            for(int i=0; i<n; i++){
                if(num&(1<<i)){
                    sub.push_back(nums[i]);
                }
            }
            res.push_back(sub);
        }
        return res;
    }

    // APPROACH -2 USING BACKTRACKING
    void f(int i, vector<int>&nums, vector<int>&ds,vector<vector<int>>&res){
        int n=nums.size();
        if(i==n){
            res.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        f(i+1,nums,ds,res);
        ds.pop_back();

        f(i+1,nums,ds,res);
    }
    vector<vector<int>> subsets(vector<int>& nums){
        vector<int>ds;
        vector<vector<int>>res;
        f(0,nums,ds,res);
        return res;
    }
};
