class Solution {
public:

    // APPROACH 1 //
    vector<vector<int>> divideArray(vector<int>& nums, int k){
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        int i=0;
        while(i<n){
            if(nums[i+2]-nums[i]>k){
                return {};
            }
            res.push_back({nums[i],nums[i+1],nums[i+2]});
            i+=3;
        }
        return res;
    }

    // APPROACH 2 //
    // vector<vector<int>> divideArray(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<vector<int>>res;
    //     sort(nums.begin(), nums.end());
    //     for(int i=0; i<=n-3; i+=3){
    //         if(nums[i+2]-nums[i]>k){
    //             return {};
    //         }
    //         res.push_back({nums[i],nums[i+1],nums[i+2]});
    //     }
    //     return res;
    // }
};
