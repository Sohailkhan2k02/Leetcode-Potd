//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int f(vector<int>&nums,int k){
        int n=nums.size();
        int i=0,j=0;
        int cnt=0;
        unordered_map<int,int>mpp;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};
