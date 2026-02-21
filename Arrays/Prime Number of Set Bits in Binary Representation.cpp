class Solution {
public:
    int countSetBits(int n){
        int count=0;
        while(n){
            n=n&(n-1);
            count++;
        }
        return count;
    }
    bool isPrime(int n){
        if(n<2)return false;
        if(n==2)return true;
        if(n%2==0)return false;

        for(int i=3;i*i<=n;i++){
            if(n%i==0)return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            int setBit=countSetBits(i);
            if(isPrime(setBit)){
                count++;
            }
        }
        return count;
    }
};
