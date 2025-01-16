//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int solve(vector<int>& nums){
        int ans = 0;
        for(int i: nums){
            ans ^= i;
        }
        return ans;
    }
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n%2==0 && m%2==0){
            return 0;
        }else if(n%2==0){
            return solve(nums1);
        }else if(m%2==0){
            return solve(nums2);
        }
        return solve(nums1)^solve(nums2);
    }
};
