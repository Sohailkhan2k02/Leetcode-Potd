class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, streak = 0;
        for(int num : nums){
            if(num == 0){
                streak++;
                cnt += streak;  // streak new subarrays ending here
            } else {
                streak = 0;     // reset if non-zero
            }
        }
        return cnt;
    }
};
