class Solution {
public:
    int smallestNumber(int n) {
        int x=n;
        while((x&(x+1))!=0){
            x=x|(x+1);
        }
        return x;
    }
};
