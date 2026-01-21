class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,-1);
        for(int i=0; i<n; i++){
            if(nums[i]%2==0) continue;
            else{
                int p=0;
                while(nums[i]>>(p+1)&1) p++;
                res[i]=(nums[i]-(1<<p));
            }
        }
        return res;
    }
};
