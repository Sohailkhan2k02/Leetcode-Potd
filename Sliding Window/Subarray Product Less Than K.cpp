//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int mul=1;
        int cnt=0;
        while(j<n){
            mul*=nums[j];
            while(mul>=k && i<=j){
                mul=mul/nums[i];
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
};
