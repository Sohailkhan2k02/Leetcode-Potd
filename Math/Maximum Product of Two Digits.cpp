class Solution {
public:
    int maxProduct(int n) {
        int first_max = 0, second_max = 0;
        while(n>0){
            int digit = n%10;
            n/=10;
            if(digit >= first_max){
                second_max = first_max;
                first_max = digit;
                continue;
            }
            if(digit > second_max) second_max = digit;
        }
        return first_max*second_max;
    }
};
