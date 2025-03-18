//T.C : O(n*n)
//S.C :O(1)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int temp = nums[0];
        int len = 1;
        int j = 0;

        for (int i = 1; i < n; i++) {
            while (j != i && (nums[i] & temp) != 0){
                temp -= nums[j];
                j++;
            }

            len = max(len, i - j + 1);
            temp += nums[i];
        }

        return len;
    }
};
