class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        int left = 0 ; 
        int maxi = INT_MIN;
        for(int right = 0 ; right < n ; right++){
            if(nums[right] == 1){
                maxi = max(right-left,maxi);
            }else{
                k++;
                if(k <= 1)
                maxi = max(right-left,maxi);
            }
            while(k >1&& left <= right){
                if(nums[left] == 0){
                    k--;
                }
                left++;
            }
        }
        if(maxi == INT_MIN) return 0;
        return maxi;
    }
};
