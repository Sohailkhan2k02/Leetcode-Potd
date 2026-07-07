class Solution {
public:
    long long sumAndMultiply(int n) {
        int x=0, sum=0, tens=1;
        for(; n; n/=10){
            const int d=n%10;
            sum+=d;
            if (d){
                x+=tens*d;
                tens*=10;
            }
        }
        return (long long)x*sum;
    }
};
