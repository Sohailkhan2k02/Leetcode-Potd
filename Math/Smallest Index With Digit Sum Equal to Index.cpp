class Solution {
public:
    int sum_digits(int n){
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n = n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(sum_digits(nums[i]) == i) return i;
        }
        return -1;

    }
};
