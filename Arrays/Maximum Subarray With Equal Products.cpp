class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), maxi = 1; 
        for(int i = 0; i < n; i++){
            long long  curr_lcm = nums[i], curr_gcd = nums[i], prod = nums[i];
            for (int j = i+1; j < n; j++) {
                curr_lcm = lcm(curr_lcm, nums[j]);
                curr_gcd = gcd(curr_gcd, nums[j]);
                prod *= nums[j];
                if(prod == curr_lcm * curr_gcd){
                    maxi = max(maxi, j - i +1);
                }
                else if (prod > curr_lcm * curr_gcd) {
                    break;
                }
            }
        }
        return maxi;
    }
};
