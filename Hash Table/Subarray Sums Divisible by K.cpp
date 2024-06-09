//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>psum(n,0);
        psum[0]=nums[0];
        for(int i=1; i<n; i++){
            psum[i]=psum[i-1]+nums[i];
        }
        for(int i=0; i<n; i++){
            cout<<psum[i];
        }
        for(int i=0; i<n; i++){
            psum[i]=(psum[i]%k+k)%k; // FOR NEGATIVE PART
            // A%K RANGE IS (0,K-1);
            //(A+B)%K==A%K + B%K;
            //(A-B)%K== (A%K - B%K + K)%K BECAUSE IF A IS NEGATIVE SO THE MODULO CANT BE NEGATIVE
            // TO AVOID NEGATIVE WE ADD K
        }
        vector<int>mpp(k,0);
        mpp[0]=1;
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt+=mpp[psum[i]];
            mpp[psum[i]]++;
        }
        return cnt;
    }
};
