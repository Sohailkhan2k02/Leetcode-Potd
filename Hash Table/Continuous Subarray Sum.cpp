//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            int rem=sum%k;
            if(mpp.find(rem)!=mpp.end() && abs(i-mpp[rem])>=2){
                return true;
            }
            else if(mpp.find(rem)==mpp.end()){
                mpp[rem]=i;
            }
        }
        return false;
    }
};
