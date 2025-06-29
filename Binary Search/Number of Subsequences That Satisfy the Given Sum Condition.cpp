class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left=0; 
        int right=n-1;
        int result=0;
        vector<int> vt(n);
        vt[0]=1;

        for(int i = 1; i < n ; i++){
            vt[i] = (vt[i-1] * 2)%mod;
        }

        while(left <= right){
            if(nums[left] + nums[right] <= target){
               result = (result + vt[right - left]) % mod;
               left++;
            }
            else{
                right--;
            }
        }
        
      return result;
    }
};
