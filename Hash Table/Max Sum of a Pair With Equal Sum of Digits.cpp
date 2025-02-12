//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> largest(82, -1);
        int max_sum = -1;

        for (int num : nums) {
            int sum_digits = 0, temp = num;
            while (temp > 0) sum_digits += temp % 10, temp /= 10;

            if (largest[sum_digits] != -1)
                max_sum = max(max_sum, num + largest[sum_digits]);
            largest[sum_digits] = max(largest[sum_digits], num);
        }
        return max_sum;
    }
};
