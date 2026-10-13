class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end(), [](const int num1, const int num2) {

            if(abs(num1) < abs(num2)) return true;

            return false;
        });

        int halfN = ceil((double)n/2);
        
        int ptr = n - 1;

        long long res = 0;
        while(halfN > 0) {
            res += 1LL * nums[ptr] * nums[ptr];
            halfN--;
            ptr--;
        }

        while(ptr >= 0) {
            res -= 1LL* nums[ptr] * nums[ptr];
            ptr--;
        }

        return res;
    }
};
