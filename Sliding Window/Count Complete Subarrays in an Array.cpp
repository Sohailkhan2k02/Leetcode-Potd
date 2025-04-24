//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(auto i:nums) mpp[i]++;
        int cnt=mpp.size();
        mpp=unordered_map<int,int>();
        int res=0,i=0,j=0;
        while(j<n){
            mpp[nums[j]]++;
            while(i<n && mpp.size()==cnt){
                res+=n-j;
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};
