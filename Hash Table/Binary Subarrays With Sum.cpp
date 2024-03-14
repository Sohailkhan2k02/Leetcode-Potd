// T.C: O(n)
// S.C: O(n)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int res=0;
        int cumSum=0;
        mpp[0]=1;
        for(auto it:nums){
            cumSum+=it;
            cout<<cumSum<<endl;
            if(mpp.find(cumSum-k)!=mpp.end()){
                res+=mpp[cumSum-k];
            }

            mpp[cumSum]++;
        }
        return res;
    }
};
