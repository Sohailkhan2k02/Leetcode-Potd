//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int n=nums.size();
        vector<int> L(n, 0), R(n, 0);
        for(int i=0; i<n-1; i++){
            L[i+1]=max(L[i], nums[i]);
            R[n-2-i]=max(R[n-i-1], nums[n-i-1]);
        }
        long long ans=0;
        for(int j=1; j<n-1; j++)
            ans=max(ans, (long long)(L[j]-nums[j])*R[j]);
        return ans;
    }
};
