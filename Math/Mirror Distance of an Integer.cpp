class Solution {
public:
    int mirrorDistance(int n) {
        int x = reverse(n);
        return abs(x-n);
    }
    int reverse(int n)
    {
        int rev=0;
        while(n>0)
        {
            int d=n%10;
            rev=rev*10+d;
            n=n/10;
        }
        return rev;
    }

};
