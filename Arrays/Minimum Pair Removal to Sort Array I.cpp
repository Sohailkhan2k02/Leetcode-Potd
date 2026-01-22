class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int result=0;
        while(!is_sorted(nums.begin(),nums.end())){
            int idx=pairs(nums);
            nums[idx]=nums[idx]+nums[idx+1];

            nums.erase(begin(nums)+idx+1);

            result++;
        }

        return result;
    }

    int pairs(vector<int>&nums){
        int minSum=INT_MAX;
        int index=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+nums[i+1]<minSum){
                index=i;
                minSum=nums[i]+nums[i+1];
            }

        }
        return index;
    }
};
