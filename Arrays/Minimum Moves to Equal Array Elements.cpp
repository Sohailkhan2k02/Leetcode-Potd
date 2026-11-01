class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int cnt=0;
        for(auto i:nums){
            cnt+=i-mini;
        }
        return cnt;
    }
};
