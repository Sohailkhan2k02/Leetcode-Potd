//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0;
        long long sum = 0;
        long long count = 0;
        int low = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            count++;
            while(sum*count >= k){
                sum -= nums[low];
                count--;
                low++;
            }
            res += count;
        }
        return res;
    }
};
